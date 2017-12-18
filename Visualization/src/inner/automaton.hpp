#ifndef _AUTOMATON_HPP
#define _AUTOMATON_HPP

#include <QThread>
#include <QStack>
#include "../input/file_worker.hpp"

class Automaton: public QThread
{
    Q_OBJECT
    
    public:
        vector<GramRule *> grammar; // Prepisovaci pravidla.
        vector<QString> nonterminals; // Radky rozkladove tabulky.
        vector<QString> terminals; // Slupce rozkladove tabulky.
        QStack<QString> stack; // Zasobnik.
        
        short r, c;
        short **table;
        
        Automaton();
        ~Automaton();
        void end();
        
    protected:
        void run();
        
    private:
        unsigned short mWaiting;
        
        bool active;
        bool running;
        
        QString sSymbol;
        QString input;
        QString result;
        
        void endProcessing(bool accept);
        void printState(bool wait);
        void createTable();
        
    signals:
        // TODO
        void setGrammar();
        void setStack();
        void setTable();
        
        void selectGrammarRow(int index);
        void selectStackRow(int index);
        void selectCell(int row, int column);
        
        void processResult(bool accept);
        void message(bool html, QString message);
        
        void inputChanged(QString done, QString process, QString future);
};

#endif