#ifndef _GRAM_RULE_HPP
#define _GRAM_RULE_HPP

#include <QString>

class GramRule
{
    public:
        GramRule(QString nonterminal, QString prodRule);
        
        QString nonterminal;
        QString prodRule;
};

#endif