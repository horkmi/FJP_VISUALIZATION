#ifndef _TABLE_HPP
#define _TABLE_HPP

#define GRAMMAR_TABLE 0
#define DECOMP_TABLE 1
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

#include "../inner/automaton.hpp"

class Table: public QTableWidget
{
    Q_OBJECT
    
    public:
        Table(const short type, Automaton *automaton, QWidget *parent = 0);
        ~Table();
        
    private:
        bool gTable, dTable, sTable;
        Automaton *automaton;
        
        QStringList hor, ver;
        
    private slots:
        void setGrammar();
        void setTable();
        void setStack();
        
        void selectRow(int index);
        void selectCell(int row, int column);
};

#endif