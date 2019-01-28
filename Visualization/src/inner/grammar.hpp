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

/**
 * Instance predstavuje bezkontextovou gramatiku.
 */ 
class Grammar: public QObject
{
    Q_OBJECT
    
    public:
        /**
         * Prazdny symbol.
         */                 
        static const QString EMPTY;
        
        /**
         * Pouze zavola reset().
         * @param QObject *parent - pointer na rodice, defaultne nullptr.         
         */                 
        Grammar(QObject *parent = nullptr);
        
        /**
         * Destruktor pouze vola clearTable();
         */                 
        ~Grammar();
        
        /**
         * @return vysledek funkce createTable().
         */                 
        bool isCorrect();
        
        /**
         * Pouze zavola reset().
         */                 
        void clear();
        
        // ---------------------------- LL FUNKCE ----------------------------
        
        /**
         * @param nonterminalIndex - index neterminalu, pro ktery se maji najit prvni terminaly.
         * @return nalezene prvni terminaly pro dany neterminal v podobe seznamu objektu,
         *         ktere mapuji index prepisovaciho pravidla na seznam prvnich terminalu. 
         */
        QList<FirstTerminals> first(int nonterminalIndex);
        
        /**
         * @param int ruleIndex - index prepisovaciho pravidla.
         * @param int startIndex - pozice od ktere se ma dale hledat dany neterminal (v pripade,
         *                         ze neterminalu bude v prepisovacim pravidle vic).
         * @return nalezene prvni terminaly pro dane prepisovaci pravidlo.          
         */                 
        FirstTerminals applyFirstRules(int ruleIndex, int startIndex);
        
        /**
         * @param int nonterminalIndex - index neterminalu, pro ktery se maji najit nasledujici terminaly.
         * @param QList<int> &forbidden - seznam jiz prohledanych neterminalu, aby nedoslo k zacykleni.
         * @return seznam nasledujicich terminalu.
         */                 
        QList<int> follow(int nonterminalIndex, QList<int> &forbidden);
        
        /**
         * @return jestli je gramatika LL(1).
         */         
        bool createTable();
        
        // -------------------------------------------------------------------
        
        /**
         * Vyuzivano pri nacitani dat ze souboru s gramatikou. Prida dany neterminal
         * a prepisovaci pravidlo do datovych struktur.         
         * @param const QString &nonterminal - neterminal.
         * @param const QList<QString> &rule - prepisovaci pravidlo.
         */         
        void append(const QString &nonterminal, const QList<QString> &rule);
        
        /**
         * @param int index - index prepisovaciho pravidla, ktere ma vyt vraceno.
         * @return prepisovaci pravidlo na danem indexu.
         */                 
        Rule getRule(int index);
        
        /**
         * @param int row - radek v tabulce prechodu.
         * @param int colum - sloupec v tabulce prechodu.
         * @return index pravidla z tabulky prechodu na danych souradnicich.         
         */                 
        int getRuleIndex(int row, int column);
        
        /**
         * U terminalu se provadi prevod do zapornych jednotek.
         * @param bool terminal - jestli jde o terminal.
         * @param const QString &word - slovo, jehoz index chceme najit.
         * @return index hledaneho terminalu ci neterminalu.
         */                 
        int getWordIndex(bool terminal, const QString &word);
        
        /**
         * @param int index - index terminalu ci neterminalu, ktery chceme prevest na text.
         * @return naopak oproti prechozi funkci, vraci text daneho terminalu ci neterminalu na danem indexu.
         */                 
        QString getWord(int index);
        
        /**
         * @return velikosti seznamu terminalu ci neterminalu.
         */                 
        int getTerminalsSize();
        int getNonterminalsSize();
        
        /**
         * Naplni bud tabulku gramatika, nebo prechodovou tabulku.
         * @param QTableWidget &table - tabulka pro naplneni.         
         */                 
        void setGrammarTable(QTableWidget &table);
        void setParsingTable(QTableWidget &table);
        
        /**
         * Vyuzivano u tabulek gramatika a zasobnik.
         * @param int index - index terminalu ci neterminalu.
         * @return jak ma byt zobrazen uzivateli (HTML syntaxe pro label).         
         */         
        QString indexToString(int index);
        
        /**
         * @param Rule &rule - prepisovaci pravidlo, ktere chceme prevest do retezce.
         * @return retezec slov vytvoreny podle indexu v danem pravidle.
         */                 
        QString ruleToString(Rule &rule);
        
        /**
         * Vyuzivano z pocatku pro debugovani.
         * @return retezec, ve kterem je obsah vsech datovych struktur.
         */                 
        QString toString();
        
        /**
         * Funkce, ktera zaridi vytvoreni popisu derivacniho stromu v DOT jazyce pro vytvoreni obrazku.
         * @param const QString &input - vstupni retezec.
         * @param const QStringList &resSeqRules - vysledna pravidla pouzita pro zpracovani vstupniho retezce.
         * @return popis derivacniho stromu v DOT jazyce.                           
         */                 
        QString toDotLanguage(const QString &input, const QStringList &resSeqRules);
        
        /**
         * Vycisti datove struktury.
         */                 
        void reset();
        
    private:
        /**
         * Seznam terminalu (znaky bud v apostrofech nebo uvozovkach).
         */         
        QList<QString> terminals;
        
        /**
         * Seznam neterminalu (vse ostatni - mely by zacinat malym pismenem dle ANTLR).
         */         
        QList<QString> nonterminals;
        
        /**
         * Prepisovaci pravidla (kazda radka jedno pravidlo).
         */         
        QList<Rule> rules;
        
        /**
         * Mapovani indexu neterminalu (nonterminals) na seznam indexu prepisovacich pravidel (rules).
         */         
        QMap<int, QList<int> > rulesIndices;
        
        /**
         * Tabulka prechodu.
         */         
        short **table;
        
        /**
         * Pridani terminalu, ci neterminalu.
         * @param const QString &terminal - terminal.
         * @param const QString &nonterminal - neterminal.
         * @return index daneho symbolu (slova).
         */                 
        int appendTerminal(const QString &terminal);
        int appendNonterminal(const QString &nonterminal);
        
        /**
         * Spolecna funkce pro funkce appendTerminal(), appendNonterminal().
         * @param QList<QString> *list - pointer bud na seznam terminalu, nebo neterminalu.
         * @param const QString &word - symbol (slovo) - terminal ci neterminal.
         * @return index daneho symbolu v seznamu.               
         */                 
        int findInList(QList<QString> *list, const QString &word);
        
        /**
         * Rekurzivni funkce pro vytvoreni derivacniho stromu + popis pro vygenerovani obrazku.
         * @param int &nodeIndex - index rodicovskeho uzlu ve stromu.
         * @param QList<int> &resRules - indexy vyslednych pravidel, ktera byla vyuzita pro zpracovani.
         * @param QString &dot - dosud vytvoreny retezec v DOT formatu.
         * @param const QString &parentNodeName - nazev rodicovskeho uzlu.
         */                 
        void toDotLanguageRec(int &nodeIndex, QList<int> &resRules, QString &dot, const QString &parentNodeName);
        
        /**
         * Uvolni pamet pridelenou tabulce prechodu.
         */                 
        void clearTable();
};

#endif