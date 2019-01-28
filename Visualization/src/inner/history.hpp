#ifndef _HISTORY_HPP
#define _HISTORY_HPP

#include <QPoint>

/**
 * Instance predstavuje jeden krok vizualizace. Slouzi pro navrat v historii.
 */ 
class History
{
    public:
        /**
         * Posledni oznacena bunka [row][column] v tabulce prechodu.
         * Dulezite az pro dalsi historicky zaznam.
         * [row], tedy souradnice x, odpovida i oznacene radce v tabulce gramatiky.
         */         
        QPoint selectedCell;
        
        
        /**
         * Index vlozeneho pravidla, pri navratu se odebere odpovidajici pocet polozek ze zasobniku.
         * !!! Pri navratu nezapomenout odebrat posledni pridane pravidlo do resultingRules. !!!
         */         
        int stackAdded;
        
        /**
         * Pokud je nastaven start, odebiram ze zasobniku pouze jednu polozku (viz. prvni krok).
         * Navic neodebiram posledni pridane pravidlo, protoze zadne pridane nebylo!!!
         */                 
        bool start;
        
        /**
         * Jestli se navysil index pro vstup (muze se navysit max. o jedna).
         */         
        bool inputIndexChanged;
        
        /**
         * Konstruktor nastavi instancni atributy na defaultni hodnoty.
         */                 
        History();
        
        /**
         * @return jestli byla zmena ve vyberu.
         */                 
        bool isSelectedCell();
        
        /**
         * @return jestli bylo na zasobnik neco pridano.
         */                 
        bool isStackAdded();
        
        /**
         * @return jestli se jednalo o prvni krok vizualizace (pridani pocatecniho symbolu).
         */                 
        bool isStart();
        
        /**
         * @return jestli byl navysen index odkazujici na vstupni retezec.
         */                 
        bool isInputIndexChanged();
        
        /**
         * @return jestli bylo ze zasobniku neco odebrano.
         */                 
        bool isStackRemoved();
        
        /**
         * @return co bylo ze zasobniku odebrano.
         */                 
        int getStackRemoved();
        
        /**
         * Zaznamena index odstraneneho symbolu ze zasobniku.
         * @param int removed - index terminalu ci neterminalu, ktery byl prave odebran ze zasobniku.
         */                 
        void setStackRemoved(int removed);
        
    private:
        /**
         * Defaultni promenna pro vetsinu hodnot. POZOR, nefunguje pro stackRemoved - proto
         * tolik atributu a funkci.         
         */                 
        static const int DEF_VALUE;
        
        /**
         * Index odebraneho terminalu ci neterminalu, pri navratu se bude pridavat.
         */         
        int stackRemoved;
        
        /**
         * U stackRemoved nemuzu vychazet z defaultni hodnoty, protoze na zasobniku muze byt cokoli!
         */         
        bool removeHappened;
};

#endif