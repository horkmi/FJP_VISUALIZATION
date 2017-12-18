#include "automaton.hpp"

Automaton::Automaton(): QThread()
{
    active = true; // Vlakno je aktivni.
    running = true; // Algoritmus je pozastaveny.
    
    mWaiting = 2000;
    
    sSymbol = FileWorker::loadGrammar(grammar);
    createTable();
    
    stack.push(sSymbol);
    input = QString("abbab");
}

Automaton::~Automaton()
{
    while (!grammar.empty())
    {
        delete grammar.back();
        grammar.pop_back();
    }
    
    for (int i = 0; i < r; i++)
    {
        delete[] table[i];
    }
    delete[] table;
}

void Automaton::end()
{
    active = false;
}

void Automaton::run()
{
    emit setGrammar();
    emit setStack();
    emit setTable();
    emit inputChanged("", "", input);
    
    while (active)
    {
        msleep(mWaiting);
        
        if (running)
        {
            printState(true);
            if (stack.isEmpty() && input.size() < 1)
            {
                endProcessing(true);
            }
            else if (!stack.isEmpty() && input.size() > 0)
            {
                QString item = stack.pop();
                
                emit inputChanged("", QString(input.at(0)), input.mid(1, input.length() - 1));
                emit setStack();
                msleep(mWaiting);
                
                short row = -1, column = -1;
                
                for (unsigned int i = 0; i < nonterminals.size(); i++)
                {
                    if (item.compare(nonterminals[i]) == 0)
                    {
                        row = i;
                        break;
                    }
                }
                
                char c = input.at(0).toLatin1();
                
                for (unsigned int i = 0; i < terminals.size(); i++)
                {
                    if (terminals[i].size() == 1 && terminals[i].at(0).toLatin1() == c)
                    {
                        column = i;
                        break;
                    }
                }
                
                // Zjistit, jake pravidlo se aplikuje - zvyraznit ho v tabulce.
                for (unsigned int i = 0; i < grammar.size(); i++)
                {
                    if (grammar[i]->nonterminal.compare(item) == 0 && QString(grammar[i]->prodRule.at(0)).compare(QString(c)) == 0)
                    {
                        emit selectGrammarRow(i);
                        break;
                    }
                }
                
                // Zjisteni pravidla + jeho aplikace + zapis do vysledneho retezce.
                int ruleNumber = table[row][column];
                result.append(QString::number(ruleNumber));
                emit selectCell(row, column);
                
                QString pItem = grammar.at(ruleNumber - 1)->prodRule;
                for (int i = pItem.size() - 1; i >= 0; i--)
                {
                    stack.push(QString(pItem.at(i)));
                }
                
                printState(false);
                
                if (input.at(0).toLatin1() == stack.pop().at(0).toLatin1())
                {
                    // Srovnani.
                    emit inputChanged(QString(input.at(0)), "", input.mid(1, input.length() - 1));
                    input.remove(0, 1);
                }
                else
                {
                    endProcessing(false);
                }
            }
            else
            {
                endProcessing(false);
            }
        }
    }
}

void Automaton::endProcessing(bool accept)
{
    if (accept)
    {
        emit message(false, QString(trUtf8("AKCEPTOVÁNO")));
        emit processResult(true);
    }
    else
    {
        emit message(false, QString(trUtf8("NEAKCEPTOVÁNO")));
        emit processResult(false);
    }
    running = false;
}

void Automaton::printState(bool wait)
{
    QString stackStr;
    for (int i = stack.size() - 1; i >= 0; i--)
    {
        stackStr.append(stack.at(i));
    }
    
    emit message(false, QString("(%1, %2, %3)").arg(input.toUtf8().data(), stackStr.toUtf8().data(), result.toUtf8().data()));
    emit setStack();
    
    msleep(100); // TODO - kdyz neni uspani, vlakno pokracuje dal a prepise zasobnik, nez se stihne zvyraznit radka v tabulce.
    if (wait)
    {
        msleep(mWaiting);
    }
}

void Automaton::createTable()
{
    // Neterminalni symboly bez opakovani.
    vector<GramRule *>::iterator i;
    vector<QString>::iterator j;
    for (i = grammar.begin(); i != grammar.end(); i++)
    {
        bool exist = false;
        for (j = nonterminals.begin(); j != nonterminals.end(); j++)
        {
            if ((*i)->nonterminal.compare(*j) == 0)
            {
                exist = true;
                break;
            }
        }
        
        if (!exist)
        {
            nonterminals.push_back((*i)->nonterminal);
        }
    }
    
    // Zjisteni terminalnich symbolu.
    terminals.push_back(QString("a"));
    terminals.push_back(QString("b"));
    
    // Vytvoreni rozkladove tabulky.
    r = nonterminals.size();
    c = terminals.size();
    
    table = new short*[r];
    for (int i = 0; i < r; i++)
    {
        table[i] = new short[c];
    }
    table[0][0] = 1;
    table[0][1] = 2;
    table[1][0] = 3;
    table[1][1] = 4;
}