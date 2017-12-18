#include "table.hpp"

Table::Table(const short type, Automaton *automaton, QWidget *parent): QTableWidget(parent)
{
    this->automaton = automaton;
    
    gTable = false;
    dTable = false;
    sTable = false;
    
    switch (type)
    {
        case GRAMMAR_TABLE:
            gTable = true;
            connect(automaton, SIGNAL(setGrammar()), this, SLOT(setGrammar()));
            connect(automaton, SIGNAL(selectGrammarRow(int)), this, SLOT(selectRow(int)));
            break;
        case DECOMP_TABLE:
            dTable = true;
            connect(automaton, SIGNAL(setTable()), this, SLOT(setTable()));
            connect(automaton, SIGNAL(selectCell(int, int)), this, SLOT(selectCell(int, int)));
            break;
        default:
            sTable = true;
            connect(automaton, SIGNAL(setStack()), this, SLOT(setStack()));
            connect(automaton, SIGNAL(selectStackRow(int)), this, SLOT(selectRow(int)));
            break;
    }
    
    horizontalHeader()->setVisible(true);
    verticalHeader()->setVisible(true);
    setShowGrid(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
}

Table::~Table()
{
}

void Table::setGrammar()
{
    setRowCount(automaton->grammar.size());
    setColumnCount(2);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    
    hor.clear();
    hor << trUtf8("Neterminál") << trUtf8("Pravidlo");
    
    ver.clear();
    for (unsigned int i = 0; i < automaton->grammar.size(); i++)
    {
        ver << QString(QString::number(i + 1) + ".");
    }
    
    setHorizontalHeaderLabels(hor);
    setVerticalHeaderLabels(ver);
    
    vector<GramRule *>::iterator i;
    int counter = -1;
    for (i = automaton->grammar.begin(); i != automaton->grammar.end(); i++)
    {
        QTableWidgetItem *item_1 = new QTableWidgetItem((*i)->nonterminal);
        QTableWidgetItem *item_2 = new QTableWidgetItem((*i)->prodRule);
        
        setItem(++counter, 0, item_1);
        setItem(counter, 1, item_2);
    }
}

void Table::setTable()
{
    setRowCount(automaton->terminals.size());
    setColumnCount(automaton->nonterminals.size());
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    vector<QString>::iterator i;
    
    hor.clear();
    for (i = automaton->terminals.begin(); i != automaton->terminals.end(); i++)
    {
        hor << *i;
    }
    
    ver.clear();
    for (i = automaton->nonterminals.begin(); i != automaton->nonterminals.end(); i++)
    {
        ver << *i;
    }
    
    setHorizontalHeaderLabels(hor);
    setVerticalHeaderLabels(ver);
    
    for (int j = 0; j < automaton->r; j++)
    {
        for (int k = 0; k < automaton->c; k++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(automaton->table[j][k]));
            setItem(j, k, item);
        }
    }
}

void Table::setStack()
{
    setRowCount(automaton->stack.size());
    setColumnCount(1);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    hor.clear();
    hor << trUtf8("Zásobník");
    
    ver.clear();
    for (int i = 0; i < automaton->stack.size(); i++)
    {
        if (i == 0)
        {
            ver << trUtf8("Vrchol");
        }
        else
        {
            ver << QString(QString::number(i + 1) + ". prvek");
        }
    }
    
    setHorizontalHeaderLabels(hor);
    setVerticalHeaderLabels(ver);
    
    for (int i = 0; i < automaton->stack.size(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(automaton->stack.at(i));
        setItem(automaton->stack.size() - i - 1, 0, item);
    }
}

void Table::selectRow(int index)
{
    QTableWidget::selectRow(index);
}

void Table::selectCell(int row, int column)
{
    setCurrentCell(row, column);
}