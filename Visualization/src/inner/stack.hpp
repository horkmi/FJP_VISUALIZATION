#ifndef _STACK_HPP
#define _STACK_HPP

#include <QStack>
#include <QString>
#include <QObject>
#include <QDebug>

#include "grammar.hpp"

/**
 * Instance predstavuje zasobnik terminalu a neterminalu, ktere cekaji na zpracovani.
 */ 
class Stack: public QObject
{
    Q_OBJECT
    
    public:
        /**
         * Prida vsechny terminaly a neterminaly z prepisovaciho pravidla do zasobniku.
         * @param Rule rule - prepisovaci pravidlo.         
         */                 
        void append(Rule rule);
        
        /**
         * Funkce pro vlozeni celociselne hodnoty na zasobnik.
         * @param int value - hodnot pro ulozeni na zasobnik.         
         */                 
        void push(int value);
        
        /**
         * Funkce pro odebrani hodnoty na vrcholu zasobniku.
         * @param int count - kolikrat se ma udelat pop(), defaultne jedna. Vyuzivano pri navratu v historii.
         * @return hodnota, ktera byla na vrcholu zasobniku.         
         */                 
        int pop(int count = 1);
        
        /**
         * @return jestli je zasobnik prazdny.
         */                 
        bool isEmpty();
        
        /**
         * Vycisti zasobnik.
         */                 
        void clear();
        
        /**
         * Vyplni tabulku v hlavnim okne, ktera predstavuje zasobnik.
         * @param QTableWidget &table - odkaz na tabulku.
         * @param Grammar &grammar - odkaz na gramatiku.                  
         */                 
        void setStackTable(QTableWidget &table, Grammar &grammar);
        
        /**
         * @param Grammar &grammar - odkaz na gramatiku.
         * @return stav zasobniku preveden na retezec.                  
         */                 
        QString toString(Grammar &grammar);
        
    private:
        /**
         * Zasobnik pro indexy terminalu a neterminalu.
         */                 
        QStack<int> stack;
        
    signals:
        /**
         * Jestli doslo ke zmene obsahu zasobniku, musi dojit k prekresleni tabulky.
         */                 
        void changed();
};

#endif