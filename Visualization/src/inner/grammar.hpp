#ifndef _GRAMMAR_HPP
#define _GRAMMAR_HPP

#include <QObject>
#include <QList>
#include <QString>

#include <QLabel>
#include <QTableWidget>
#include <QAbstractItemView>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QStringList>

#include <QDebug>

#include "rule.hpp"
#include "first_terminals.hpp"

class Grammar: public QObject
{
    Q_OBJECT
    
    public:
        static const QString EMPTY;
        
        Grammar(QObject *parent = nullptr);
        ~Grammar();
        
        // TODO!!!
        bool isCorrect();
        void clear();
        
        // LL FUNKCE!
        QList<FirstTerminals> first(int nonterminalIndex);
        FirstTerminals applyFirstRules(int ruleIndex, int startIndex);
        QList<int> follow(int nonterminalIndex, QList<int> &forbidden);
        void createTable();
        
        // Pro nacteni dat ze souboru s gramatikou.
        void append(const QString &nonterminal, const QList<QString> &rule);
        // int index - zaporna terminaly, kladna neterminaly.
        QString getWord(int index);
        Rule getRule(int index);
        int getRuleIndex(int row, int column);
        int getWordIndex(bool terminal, const QString &word);
        
        int getTerminalsSize();
        int getNonterminalsSize();
        
        void setGrammarTable(QTableWidget &table);
        void setParsingTable(QTableWidget &table);
        
        QString indexToString(int index); // Rozdeleni ruleToString kvuli zobrazeni v zasobniku (index = index terminalu ci neterminalu).
        QString ruleToString(Rule &rule);
        QString toString();
        QString toDotLanguage(const QString &input, const QStringList &resSeqRules);
        void reset();
        
    private:
        // Seznam terminalu (znaky bud v apostrofech nebo uvozovkach).
        QList<QString> terminals;
        
        // Seznam neterminalu (vse ostatni - mely by zacinat malym pismenem dle ANTLR).
        QList<QString> nonterminals;
        
        // Prepisovaci pravidla (kazda radka jedno pravidlo).
        QList<Rule> rules;
        
        // Mapovani indexu neterminalu (nonterminals) na seznam indexu v tabulce pravidel (rules).
        QMap<int, QList<int> > rulesIndices;
        
        // Tabulka prechodu.
        short **table;
        
        int appendTerminal(const QString &terminal);
        int appendNonterminal(const QString &nonterminal);
        int findInList(QList<QString> *list, const QString &word);
        void toDotLanguageRec(int &nodeIndex, QList<int> &resRules, QString &dot, const QString &parentNodeName);
};

#endif