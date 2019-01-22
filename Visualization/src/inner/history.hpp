#ifndef _HISTORY_HPP
#define _HISTORY_HPP

#include <QPoint>

class History
{
    public:
        // Posledni oznacena bunka [row][column] v tabulce prechodu. Dulezite az pro dalsi hist. zaznam.
        // [row] odpovida i oznacene radce v tabulce gramatiky.
        QPoint selectedCell;
        
        
        // Index vlozeneho pravidla, pri navratu se odebere odpovidajici pocet polozek ze zasobniku.
        // !!! Pri navratu nezapomenout odebrat posledni pridane pravidlo do resultingRules. !!!
        int stackAdded;
        bool start; // Pokud je nastaven start, odebiram ze zasobniku pouze jednu polozku (viz. prvni krok).
                    // Navic neodebiram posledni pridane pravidlo, protoze zadne pridane nebylo!!! TODO???
        
        // Jestli se navysil index pro vstup (muze se navysit max. o jedna).
        bool inputIndexChanged;
        
        History();
        
        bool isSelectedCell();
        bool isStackAdded();
        bool isStart();
        bool isInputIndexChanged();
        
        bool isStackRemoved();
        int getStackRemoved();
        void setStackRemoved(int removed);
        
    private:
        static const int DEF_VALUE;
        
        // Index odebraneho terminalu/neterminalu, pri navratu se bude pridavat.
        int stackRemoved;
        
        // U removed nemuzu vychazet z defaultni hodnoty, protoze na zasobniku muze byt cokoli!
        bool removeHappened;
};

#endif