#include "gram_rule.hpp"

GramRule::GramRule(QString nonterminal, QString prodRule)
{
    this->nonterminal = nonterminal;
    this->prodRule = prodRule;
}