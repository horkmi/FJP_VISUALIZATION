#include "rule.hpp"

Rule::Rule(int nonterminal, const QList<int> &rule)
{
    this->nonterminal = nonterminal;
    this->rule = rule;
}

QList<int> Rule::findNonterminal(int nonterminal)
{
    QList<int> results;
    
    int index = -1;
    while ((index = rule.indexOf(nonterminal, index + 1)) >= 0)
    {
        results.append(index);
    }
    
    return results;
}

int Rule::getNonterminal()
{
    return nonterminal;
}

QList<int> Rule::getRule()
{
    return rule;
}