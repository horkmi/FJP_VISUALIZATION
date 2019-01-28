#ifndef _TABLE_HPP
#define _TABLE_HPP

// Tabulka pro gramatiku.
#define GRAMMAR_TABLE 0
// Prechodova tabulka.
#define PARSING_TABLE 1
// Tabulka pro zasobnik.
#define STACK_TABLE 2

#include <QWidget>
#include <QVBoxLayout>

#include <QTableWidget>
#include <QApplication>
#include <QAbstractItemView>
#include <QTableWidgetItem>
#include <QDesktopWidget>
#include <QHeaderView>
#include <QStringList>
#include <QMouseEvent>

#include "../inner/automaton.hpp"

/**
 * Instance tridy Table predstavuji zobrazovane tabulky v hlavnim okne.
 */ 
class Table: public QTableWidget
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavuje spolecne prvky tabulek.
         * @param const short type - o jakou jde tabulku.
         * @param Automaton *automaton - pointer na automat.
         * @param QWidget *parent - pointer na rodice, defaultne nula.
         */                 
        Table(const short type, Automaton *automaton, QWidget *parent = 0);
        
    public slots:
        /**
         * Vola funkce pro vycisteni a naplneni novymi daty.
         */                 
        void set();
        
    protected:
        // Blokovat akce mysi na vsechny tabulky (nechceme, aby uzivatel zasahoval do animace).
        void mouseDoubleClickEvent(QMouseEvent */*event*/) {};
        void mouseMoveEvent(QMouseEvent */*event*/) {};
        void mousePressEvent(QMouseEvent */*event*/) {};
        void mouseReleaseEvent(QMouseEvent */*event*/) {};
        
    private:
        /**
         * Jestli jde o tabulku gramatika, prechodova tabulka, zasobnik.
         */                 
        bool gTable, pTable, sTable;
        
        /**
         * Pointer na automat kvuli volani funkci pro prekresleni.
         */                 
        Automaton *automaton;
        
        /**
         * Aktualne vybrana radka.
         */                 
        int actRow;
        
        /**
         * Vrati styly labelu v druhem sloupecku v tabulce gramatika (je tam vkladan
         * label, jehoz styly se nemeni automaticky pri vyberu).
         */                 
        void changeStyleBack();
        
    private slots:
        /**
         * Vybere radku na danem indexu.
         * @param int index - index radky.         
         */                 
        void selectRow(int index);
        
        /**
         * Vybere konkretni bunku.
         * @param int row - index radku.
         * @param int column - index sloupce.       
         */                 
        void selectCell(int row, int column);
        
        /**
         * Odstrani vyber v tabulce a vrati nahled na prvni bunku.
         */                 
        void clearSelection();
};

#endif