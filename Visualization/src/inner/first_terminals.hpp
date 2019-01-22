#ifndef _FIRST_TERMINALS_HPP
#define _FIRST_TERMINALS_HPP

#include <QList>

class FirstTerminals
{
    public:
        FirstTerminals(int ruleIndex);
        
        bool containsEmptySymbol();
        void removeEmptySymbol();
        void appendTerminal(int firstTerminal);
        void appendTerminals(const QList<int> &firstTerminals);
        int getRuleIndex();
        QList<int> getFirstTerminals();
        
    private:
        int ruleIndex;
        QList<int> firstTerminals;
};

#endif