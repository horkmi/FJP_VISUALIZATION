#ifndef _RULE_HPP
#define _RULE_HPP

#include <QList>

class Rule
{
    public:
        Rule(int nonterminal, const QList<int> &rule);
        QList<int> findNonterminal(int nonterminal);
        int getNonterminal();
        QList<int> getRule();
        
    private:
        int nonterminal;
        QList<int> rule; // Indexy terminalu, neterminalu. Zaporna cisla terminaly, kladna neterminaly.
};

#endif