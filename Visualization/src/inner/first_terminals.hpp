#ifndef _FIRST_TERMINALS_HPP
#define _FIRST_TERMINALS_HPP

#include <QList>

/**
 * Instance predstavuji nalezeny seznam prvnich terminalu pro konkretni pravidlo.
 */ 
class FirstTerminals
{
    public:
        /**
         * Konstruktor nastavi index prepisovaciho pravidla.
         * @param int ruleIndex - index prepisovaciho pravidla.         
         */                 
        FirstTerminals(int ruleIndex);
        
        /**
         * @return jestli je mezi terminaly i prazdny symbol.
         */                 
        bool containsEmptySymbol();
        
        /**
         * Odstrani prazdny symbol ze seznamu.
         */                 
        void removeEmptySymbol();
        
        /**
         * Prida index terminalu do seznamu.
         * @param int firstTerminal - pridavany index terminalu.         
         */                 
        void appendTerminal(int firstTerminal);
        
        /**
         * Prida vice indexu terminalu do seznamu.
         * @param const QList<int> &firstTerminals - seznam indexu, ktere se maji pridat.
         */                 
        void appendTerminals(const QList<int> &firstTerminals);
        
        /**
         * @return index prepisovaciho pravidla pro ktere byly nalezeny prvni terminaly.
         */                 
        int getRuleIndex();
        
        /**
         * @return seznam nalezenych prvnich terminalu.
         */                 
        QList<int> getFirstTerminals();
        
    private:
        /**
         * Index prepisovaciho pravidla.
         */                 
        int ruleIndex;
        
        /**
         * Seznam nalezenych prvnich terminalu.
         */                 
        QList<int> firstTerminals;
};

#endif