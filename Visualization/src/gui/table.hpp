#ifndef _TABLE_HPP
#define _TABLE_HPP

#define GRAMMAR_TABLE 0
#define PARSING_TABLE 1
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

class Table: public QTableWidget
{
    Q_OBJECT
    
    public:
        Table(const short type, Automaton *automaton, QWidget *parent = 0);
        
    public slots:
        void set();
        
        /*
         * Blokovat akce mysi na vsechny tabulky (nechceme, aby uzivatel zasahoval do animace).
         */         
    protected:
        void mouseDoubleClickEvent(QMouseEvent */*event*/) {};
        void mouseMoveEvent(QMouseEvent */*event*/) {};
        void mousePressEvent(QMouseEvent */*event*/) {};
        void mouseReleaseEvent(QMouseEvent */*event*/) {};
        
    private:
        bool gTable, pTable, sTable;
        Automaton *automaton;
        
        int actRow;
        
        void changeStyleBack();
        
    private slots:
        void selectRow(int index);
        void selectCell(int row, int column);
        void clearSelection();
};

#endif