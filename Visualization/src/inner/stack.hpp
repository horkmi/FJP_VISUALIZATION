#ifndef _STACK_HPP
#define _STACK_HPP

#include <QStack>
#include <QString>
#include <QObject>
#include <QDebug>

#include "grammar.hpp"

// Zasobnik - obsahuje ID casti prepisovacich pravidel (nazvu (ne)terminalu).
class Stack: public QObject
{
    Q_OBJECT
    
    public:
        void append(Rule rule);
        void push(int value);
        int pop(int count = 1); // Kolik se ma udelat pop() - vyuzivano pri navratu v historii.
        bool isEmpty();
        void clear();
        
        void setStackTable(QTableWidget &table, Grammar &grammar);
        QString toString(Grammar &grammar);
        
    private:
        QStack<int> stack;
        
    signals:
        void changed();
};

#endif