#include "grammar.hpp"

const QString Grammar::EMPTY = QString("ε");

Grammar::Grammar(QObject *parent): QObject(parent)
{
    reset();
}

Grammar::~Grammar()
{
    clearTable();
}

bool Grammar::isCorrect()
{
    return createTable();
}

void Grammar::clear()
{
    reset();
}

bool Grammar::createTable()
{
    // Vytvoreni rozkladove tabulky - nezapomenout, ze u nonterminals a terminals jsou na nultych indexech blokace.
    table = new short*[getNonterminalsSize()];
    for (int i = 0; i < getNonterminalsSize(); i++)
    {
        // Nezapomenout na sloupecek pro EMPTY.
        table[i] = new short[getTerminalsSize() + 1];
        for (int j = 0; j < getTerminalsSize() + 1; j++)
        {
            table[i][j] = -1;
        }
        
        int mustBeFollow = -1;
        QList<FirstTerminals> firstTerminals = first(i + 1);
        for (int j = 0; j < firstTerminals.size(); j++)
        {
            int ruleIndex = firstTerminals[j].getRuleIndex();
            
            if (firstTerminals[j].containsEmptySymbol())
            {
                mustBeFollow = ruleIndex;
            }
            
            for (int k = 0; k < firstTerminals[j].getFirstTerminals().size(); k++)
            {
                int column = firstTerminals[j].getFirstTerminals().at(k) - 1;
                if (table[i][column] >= 0)
                {
                    // V dane bunce je uz jine cislo.
                    qDebug() << "FF kolize = gramatika neni LL(1).";
                    return false;
                }
                else
                {
                    table[i][column] = ruleIndex;
                }
            }
        }
        
        if (mustBeFollow == -1)
        {
            continue;
        }
        
        QList<int> forbidden;
        QList<int> followTerminals = follow(i + 1, forbidden);
        
        if (followTerminals.size() < 1)
        {
            // Ve first() byl prazdny symbol, ale ve follow() nic neni -> pridat prechod pro konec vstupniho retezce.
            table[i][getTerminalsSize()] = mustBeFollow;
        }
        else
        {
            for (int j = 0; j < followTerminals.size(); j++)
            {
                int column = followTerminals.at(j) - 1;
                // Pro jednoduchost kontrolovat dulicitni indexy az tady.
                if (table[i][column] >= 0 && table[i][column] != mustBeFollow)
                {
                    // V dane bunce je uz jine cislo.
                    qDebug() << "FFL kolize = gramatika neni LL(1).";
                    return false;
                }
                else
                {
                    table[i][column] = mustBeFollow;
                }
            }
        }
    }
    
    return true;
}

QList<FirstTerminals> Grammar::first(int nonterminalIndex)
{
    // Indexy (kladne) prvnich terminalu.
    QList<FirstTerminals> results;
    
    for (int i = 0; i < rulesIndices.value(nonterminalIndex).size(); i++)
    {
        // Prochazime vsechna prepisovaci pravidla pro dane neterminaly.
        results.append(applyFirstRules(rulesIndices.value(nonterminalIndex).at(i), 0));
    }
    
    return results;
}

FirstTerminals Grammar::applyFirstRules(int ruleIndex, int startIndex)
{
    // Projit vsechny moznosti, pouze pokud na prave strane neco je.
    // 1. pouze prazdny symbol.
    // 2. jako prvni je terminal.
    // 3. jako prvni je neterminal - pokud je pak v mnozime prvnich terminalu prazdny symbol
    //    a za neterminalem se nachazi neco dalsiho, odstranit prazdny symbol a sjednotit
    //    seznam prvnich terminalu se seznamem z prozkoumavani toho dalsiho.
    FirstTerminals results(ruleIndex);
    if (startIndex < rules[ruleIndex].getRule().size())
    {
        if (rules[ruleIndex].getRule().at(startIndex) == 0)
        {
            if (rules[ruleIndex].getRule().size() == 1)
            {
                // Prepisovaci pravidlo = pouze prazdny symbol.
                results.appendTerminal(0);
            }
            else
            {
                results.appendTerminals(applyFirstRules(ruleIndex, ++startIndex).getFirstTerminals());
            }
        }
        else if (rules[ruleIndex].getRule().at(startIndex) < 0)
        {
            // Terminal.
            results.appendTerminal(rules[ruleIndex].getRule().at(startIndex) * -1);
        }
        else if (rules[ruleIndex].getRule().at(startIndex) > 0)
        {
            // Neterminal.
            QList<FirstTerminals> otherNonterminal = first(rules[ruleIndex].getRule().at(startIndex));
            for (int i = 0; i < otherNonterminal.size(); i++)
            {
                results.appendTerminals(otherNonterminal[i].getFirstTerminals());
            }
            
            // Zjistovat jestli neni v seznamu prazdny symbol pouze pokud jeste nejsme na konci.
            if (rules[ruleIndex].getRule().size() > startIndex + 1 && results.containsEmptySymbol())
            {
                results.removeEmptySymbol();
                results.appendTerminals(applyFirstRules(ruleIndex, ++startIndex).getFirstTerminals());
            }
        }
    }
    return results;
}

QList<int> Grammar::follow(int nonterminalIndex, QList<int> &forbidden)
{
    QList<int> results;
    if (!forbidden.contains(nonterminalIndex))
    {
        forbidden.append(nonterminalIndex);
        for (int i = 0; i < rules.size(); i++)
        {
            // Indexy daneho neterminalu ve vybranem pravidle.
            QList<int> nonterminalIndices = rules[i].findNonterminal(nonterminalIndex);
            
            for (int j = 0; j < nonterminalIndices.size(); j++)
            {
                FirstTerminals followTerminals = applyFirstRules(i, nonterminalIndices.at(j) + 1);
                if (followTerminals.containsEmptySymbol())
                {
                    followTerminals.removeEmptySymbol();
                    results.append(followTerminals.getFirstTerminals());
                    results.append(follow(rules[i].getNonterminal(), forbidden));
                }
                else if (nonterminalIndices.at(j) + 1 >= rules[i].getRule().size())
                {
                    // Znak je na konci (do mnoziny spadnou nasledujici terminaly z neterminalu na leve strane
                    // pravidla a v tabulce se vyplni polozka ve sloupecku EMPTY).
                    results.append(follow(rules[i].getNonterminal(), forbidden));
                    results.append(terminals.size()); // Predstavujici EMPTY (neni ani terminal ani neterminal -> neni ulozeny v seznamu - vsude se s nim pracuje jako s nulou, pouze pro graficky vystup jde o index sloupce v tabulce).
                }
                else
                {
                    results.append(followTerminals.getFirstTerminals());
                }
            }
        }
    }
    return results;
}

void Grammar::append(const QString &nonterminal, const QList<QString> &rule)
{
    int nonterminalIndex;
    QList<int> ruleIndices;
    
    nonterminalIndex = appendNonterminal(nonterminal);
    for (int i = 0; i < rule.size(); i++)
    {
        int id;
        
        if (rule.at(i).compare(EMPTY) == 0)
        {
            // Prazdny symbol - jako pod indexem nula (neni nikde ulozeny).
            id = 0;
        }
        else if ((rule.at(i).startsWith("'") && rule.at(i).endsWith("'")) || (rule.at(i).startsWith("\"") && rule.at(i).endsWith("\"")))
        {
            // Jedna se o terminal - kontrola, pripadne pridani do seznamu.
            QString terminal = rule.at(i).mid(1, rule.at(i).length() - 2);
            id = appendTerminal(terminal);
        }
        else
        {
            // Neterminal - kontrola, pripadne pridani do seznamu.
            id = appendNonterminal(rule.at(i));
        }
        
        ruleIndices.append(id);
    }
    
    if (!rulesIndices.contains(nonterminalIndex))
    {
        rulesIndices.insert(nonterminalIndex, QList<int>());
    }
    rulesIndices[nonterminalIndex].append(rules.size());
    
    Rule newRule(nonterminalIndex, ruleIndices);
    rules.append(newRule);
}

QString Grammar::getWord(int index)
{
    QString results;
    
    if (index == 0)
    {
        results.append(EMPTY);
    }
    else if (index < 0 && (index * -1) < terminals.size())
    {
        results.append(terminals.at(index * -1));
    }
    else if (index > 0 && index < nonterminals.size())
    {
        results.append(nonterminals.at(index));
    }
    
    return results;
}

Rule Grammar::getRule(int index)
{
    return rules.at(index);
}

int Grammar::getRuleIndex(int row, int column)
{
    return table[row][column];
}

int Grammar::getWordIndex(bool terminal, const QString &word)
{
    if (word.compare(EMPTY) == 0)
    {
        return 0;
    }
    else if (terminal)
    {
        return terminals.indexOf(word);
    }
    else
    {
        return nonterminals.indexOf(word);
    }
}

int Grammar::appendTerminal(const QString &terminal)
{
    return findInList(&terminals, terminal) * -1;
}

int Grammar::appendNonterminal(const QString &nonterminal)
{
    return findInList(&nonterminals, nonterminal);
}

int Grammar::findInList(QList<QString> *list, const QString &word)
{
    int id;
    // Nulty index nevyhleda nikdy - na nultem indexu je veta (a prazdny symbol je odchycen driv).
    if ((id = list->indexOf(word)) < 0)
    {
        list->append(word);
        id = list->indexOf(word);
    }
    return id;
}

int Grammar::getTerminalsSize()
{
    return terminals.size() - 1;
}

int Grammar::getNonterminalsSize()
{
    return nonterminals.size() - 1;
}

void Grammar::setGrammarTable(QTableWidget &table)
{
    table.setRowCount(0); // Vymaze vsechny radky.
    table.setRowCount(rules.size());
    
    QStringList ver;
    for (int i = 0; i < rules.size(); i++)
    {
        ver << QString(QString::number(i + 1) + ".");
    }
    table.setVerticalHeaderLabels(ver);
    
    for (int i = 0; i < rules.size(); i++)
    {
        table.setItem(i, 0, new QTableWidgetItem(nonterminals.at(rules[i].getNonterminal())));
        QLabel *label = new QLabel(ruleToString(rules[i]));
        label->setObjectName("grammar_table");
        label->setProperty("value", "rule");
        table.setCellWidget(i, 1, label);
    }
}

void Grammar::setParsingTable(QTableWidget &table)
{
    // Probiha jednou, pouze po nacteni gramatiky.
    
    // Vymazat vsechny radky a sloupce.
    table.setRowCount(0);
    table.setColumnCount(0);
    
    table.setRowCount(getNonterminalsSize());
    table.setColumnCount(getTerminalsSize() + 1); // +1 kvuli EMPTY.
    
    QStringList hor;
    for (int i = 1; i <= getTerminalsSize(); i++)
    {
        hor << getWord(i * -1);
    }
    hor << Grammar::EMPTY;
    
    QStringList ver;
    for (int i = 1; i <= getNonterminalsSize(); i++)
    {
        ver << getWord(i);
    }
    
    table.setHorizontalHeaderLabels(hor);
    table.setVerticalHeaderLabels(ver);
    
    for (int i = 0; i < getNonterminalsSize(); i++)
    {
        for (int j = 0; j <= getTerminalsSize(); j++) // <= kvuli EMPTY.
        {
            if (this->table[i][j] >= 0)
            {
                table.setItem(i, j, new QTableWidgetItem(QString::number(this->table[i][j] + 1)));
            }
        }
    }
}

QString Grammar::indexToString(int index)
{
    QString results;
    if (index < 0)
    {
        results.append("<b><i>");
    }
    else if (index == 0)
    {
        results.append("<span style=\"font-weight: bold; font-style: italic; color: #D30000;\">");
    }
    
    results.append(getWord(index));
    
    if (index < 0)
    {
        results.append("</i></b>");
    }
    else if (index == 0)
    {
        results.append("</span>");
    }
    return results;
}

QString Grammar::ruleToString(Rule &rule)
{
    QString results;
    for (int i = 0; i < rule.getRule().size(); i++)
    {
        if (i != 0)
        {
            results.append(" ");
        }
        results.append(indexToString(rule.getRule().at(i)));
    }
    return results;
}

QString Grammar::toString()
{
    QString results;
    for (int i = 0; i < rules.size(); i++)
    {
        QString nonterminal = nonterminals[rules[i].getNonterminal()];
        QString rule;
        for (int j = 0; j < rules[i].getRule().size(); j++)
        {
            rule.append(" ");
            
            int ruleIndex = rules[i].getRule()[j];
            if (ruleIndex < 0)
            {
                rule.append(terminals.at(ruleIndex * -1));
            }
            else if (ruleIndex > 0)
            {
                rule.append(nonterminals.at(ruleIndex));
            }
            else
            {
                rule.append(EMPTY);
            }
        }
        
        results.append(nonterminal + " :" + rule + "\n");
    }
    
    results.append("\n");
    
    QMapIterator<int, QList<int> > i(rulesIndices);
    while (i.hasNext())
    {
        i.next();
        QString indices;
        for (int j = 0; j < i.value().size(); j++)
        {
            indices.append(QString::number(i.value().at(j)) + " ");
        }
        results.append(getWord(i.key()) +  " : " + indices + "\n");
    }
    return results;
}

QString Grammar::toDotLanguage(const QString &input, const QStringList &resSeqRules)
{
    QString dot("graph \"\"\n{\n");
    dot.append("node [style=filled fillcolor=brown fontcolor=white]\n");
    dot.append("label=\"Pro vstup: " + input + "\"\n");
    
    QList<int> resRules;
    for (int i = 0; i < resSeqRules.size(); i++)
    {
        resRules.append(resSeqRules.at(i).trimmed().toInt() - 1);
    }
    
    int nodeIndex = -1;
    
    QString nodeName("node_" + QString::number(++nodeIndex));
    dot.append(nodeName + " ;\n");
    dot.append(nodeName + " [label=\"" + nonterminals.at(1) + "\" fillcolor=black] ;\n");
    
    toDotLanguageRec(nodeIndex, resRules, dot, nodeName);
    
    dot.append("}");
    return dot;
}

void Grammar::toDotLanguageRec(int &nodeIndex, QList<int> &resRules, QString &dot, const QString &parentNodeName)
{
    int resRuleIndex = resRules.takeFirst();
    
    for (int i = 0; i < rules[resRuleIndex].getRule().size(); i++)
    {
        QString nodeName("node_" + QString::number(++nodeIndex));
        dot.append(parentNodeName + " -- " + nodeName + " ;\n");
        
        int index = rules[resRuleIndex].getRule().at(i);
        if (index < 0)
        {
            dot.append(nodeName + " [label=\"" + terminals.at(index * -1) + "\" fillcolor=darkgreen] ;\n");
        }
        else if (index > 0)
        {
            dot.append(nodeName + " [label=\"" + nonterminals.at(index) + "\"] ;\n");
            toDotLanguageRec(nodeIndex, resRules, dot, nodeName);
        }
        else
        {
            dot.append(nodeName + " [label=\"" + EMPTY + "\" fillcolor=darkgreen] ;\n");
        }
    }
}

void Grammar::reset()
{
    terminals.clear();
    nonterminals.clear();
    rules.clear();
    rulesIndices.clear();
    clearTable();
    
    terminals.append("BLOCKED INDEX");
    nonterminals.append("BLOCKED INDEX");
}

void Grammar::clearTable()
{
    for (int i = 0; i < getNonterminalsSize(); i++)
    {
        delete[] table[i];
    }
    delete[] table;
    table = nullptr;
}