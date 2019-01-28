#ifndef _RULE_HPP
#define _RULE_HPP

#include <QList>

/**
 * Instance tridy Rule predstavuji prepisovaci pravidla.
 */ 
class Rule
{
    public:
        /**
         * @param int nonterminal - index neterminalu, ktereho se prepisovaci pravidlo tyka.
         * @param const QList<int> &rule - indexy terminalu a neterminalu v prepisovacim pravidle.
         */                 
        Rule(int nonterminal, const QList<int> &rule);
        
        /**
         * @param int nonterminal - index neterminalu, ktery se ma najit v prepisovacim pravidle.
         * @return seznam indexu, na kterych se dany neterminal nachazi.         
         */                 
        QList<int> findNonterminal(int nonterminal);
        
        /**
         * @return index neterminalu.
         */                 
        int getNonterminal();
        
        /**
         * @return seznam indexu terminalu a neterminalu v prepisovacim pravidle.
         */                 
        QList<int> getRule();
        
    private:
        /**
         * Index neterminalu.
         */                 
        int nonterminal;
        
        /**
         * Indexy terminalu a neterminalu v prepisovacim pravidle.
         * Zaporna cisla terminaly, kladna neterminaly, nula prazdny symbol.         
         */                 
        QList<int> rule;
};

#endif