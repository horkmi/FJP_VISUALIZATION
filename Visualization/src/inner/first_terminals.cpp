#include "first_terminals.hpp"

FirstTerminals::FirstTerminals(int ruleIndex)
{
    this->ruleIndex = ruleIndex;
}

bool FirstTerminals::containsEmptySymbol()
{
    return firstTerminals.contains(0);
}

void FirstTerminals::removeEmptySymbol()
{
    firstTerminals.removeOne(0);
}

void FirstTerminals::appendTerminal(int firstTerminal)
{
    firstTerminals.append(firstTerminal);
}

void FirstTerminals::appendTerminals(const QList<int> &firstTerminals)
{
    this->firstTerminals.append(firstTerminals);
}

int FirstTerminals::getRuleIndex()
{
    return ruleIndex;
}

QList<int> FirstTerminals::getFirstTerminals()
{
    return firstTerminals;
}