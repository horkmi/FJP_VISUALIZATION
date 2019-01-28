#ifndef _AUTOMATON_HPP
#define _AUTOMATON_HPP

#include <QDebug>
#include <QTimer>

#include "history.hpp"
#include "stack.hpp"
#include "../io/file_worker.hpp"

/**
 * Instance tridy Automaton predstavuje zasobnikovy automat.
 */ 
class Automaton: public QObject
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavi atributy na pocatecni hodnoty, vytvori instanci
         * casovace, propoji jeho signal timeout() se slotem oneStep() a nastavi
         * pocatecni vstupni text.
         * @param const QString &input - pocatecni vstupni text.
         * @param QObject *parent - pointer na rodice, defaultne nullptr.
         */                 
        Automaton(const QString &input, QObject *parent = nullptr);
        
        /**
         * Destruktor ukonci casovac a uvolni pamet, ktera mu byla pridelena.
         */                 
        ~Automaton();
        
        // ------------------------- OVLADANI ANIMACE -------------------------
        
        /**
         * Spusti prehravani.
         */                 
        void play();
        
        /**
         * Zastavi animaci.
         */                 
        void pause();
        
        /**
         * Vrati se ve zpracovani o jeden krok zpet.
         */                 
        void prevStep();
        
        /**
         * Vykona jeden krok zpracovani.
         */                 
        void nextStep();
        
        /**
         * Vrati zpracovani na zacatek.
         */                 
        void reset();
        
        /**
         * Zmeni dobu cekani mezi jednotlivymi kroky animace.
         * @param double speed - rychlost animace, ktera se musi prevest na dobu cekani.         
         */                 
        void changeWaiting(double speed);
        
        /**
         * Nastavi novy vstupni retezec, ktery ma byt zpracovany.
         * @param const QString &input - novy vstupni retezec.         
         */                 
        void setInput(const QString &input);
        
        // --------------------------------------------------------------------
        
        /**
         * @return jestli uz byl vykonany nejaky krok zpracovani.
         */                 
        bool hasHistory();
        
        /**
         * @return odkaz na gramatiku.
         */                 
        Grammar &getGrammar();
        
        /**
         * @return odkaz na zasobnik.
         */                 
        Stack &getStack();
        
        /**
         * @return odkaz na vysledna pravidla, ktera byla pouzita pro zpracovani vstupniho retezce.
         */                 
        const QStringList &getResultingRules();
        
        /**
         * @return cast vstupniho retezce, ktera uz byla zpracovana.
         */                 
        QString getDonePart();
        
        /**
         * @return slovo, ktere je aktualne zpracovavane.
         */                 
        QString getProcessingPart();
        
        /**
         * @return cast vstupniho retezce, ktera teprve ceka na zpracovani.
         */                 
        QString getWaitingPart();
        
    private:
        /**
         * Zakladni cekaci doba mezi jednotlivymi kroky zpracovani (pri spustene animaci).
         */                 
        static const unsigned short BASE_MILLI_WAITING;
        
        /**
         * Jestli uz doslo ke konci zpracovani. Kvuli tomu, aby se neopakovalo vypisovani
         * informaci o stavu automatu (misto toho se ma vypsat jestli byl retezec
         * akceptovan).         
         */                 
        bool end;
        
        /**
         * Casovac pro animaci.
         */                 
        QTimer *timer;
        
        /**
         * Aktualni cekani mezi jednotlivymi kroky zpracovani (pri spustene animaci).
         */                 
        unsigned short milliWaiting;
        
        /**
         * Instance gramatiky.
         */                 
        Grammar grammar;
        
        /**
         * Instance zasobniku.
         */                 
        Stack stack;
        
        /**
         * Historie zmen stavu automatu.
         */                 
        QList<History> changes;
        
        /**
         * Rozparsovany vstup na jednotliva slova.
         */                 
        QStringList input;
        
        /**
         * Index ukazujici na prave zpracovavanou cast vstupniho retezce.
         */                 
        int inputIndex;
        
        /**
         * Indexy vyslednych pravidel, ktere byly pouzity pro zpracovani vstupniho retezce.
         */                 
        QStringList resultingRules;
        
        /**
         * Tahle funkce je zavolana pri dokonceni zpracovani vstupniho retezce.
         * Zastavi casovac, vyhodi signaly pro zruseni vyberu bunek v tabulkach a
         * pro zobrazeni vysledku zpracovani.
         * @param bool accept - jestli byl retezec akceptovan.         
         */                 
        void endProcessing(bool accept);
        
        /**
         * Slouzi k vypisu aktualniho stavu automatu. Format prevzat ze cviceni
         * (zbyvajici slova na vstupu, stav zasobniku, seznam pouzitych pravidel).
         * Primo nevypisuje, vyhazuje signal, ktery je odchycen v MainWindow a
         * presmerovan do funkce, ktera provede fyzicke vlozeni textu do textove
         * oblasti.                           
         */                 
        void printState();
        
    private slots:
        /**
         * Provede jeden krok zpracovani automatu.
         */                 
        void oneStep();
        
    signals:
        /**
         * Zmeny v historii - pro pristupnost krokovacich tlacitek.
         */                 
        void hasNewHistory();
        void hasNotHistory();
        void hasNextStep();
        
        /**
         * Pro zruseni vyberu radky, popr. bunky.
         */                 
        void clearSelection();
        
        /**
         * Pro vyber radky, popr. bunky.
         * @param int index - index radku v tabulce gramatika.
         * @param int row - index radku v prechodove tabulce.
         * @param int column - index sloupce v prechodove tabulce.                          
         */                 
        void selectGrammarRow(int index);
        void selectParsingTableCell(int row, int column);
        
        /**
         * Doslo ke konci zpracovani, nastavit vysledny text v hlavnim okne.
         * @bool accept - jestli byl retezec akceptovan.         
         */                 
        void processResult(bool accept);
        
        /**
         * Pro vlozeni textu do textove oblasti.
         * @param bool html - jestli obsahuje HTML atributy.
         * @param QString message - text ke vlozeni.                  
         */                 
        void message(bool html, QString message);
        
        /**
         * Byl zmenen index ukazujici na aktualne zpracovavane slovo.
         */                 
        void inputChanged();
};

#endif