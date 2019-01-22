#include "table.hpp"

Table::Table(const short type, Automaton *automaton, QWidget *parent): QTableWidget(parent)
{
    this->automaton = automaton;
    
    gTable = false;
    pTable = false;
    sTable = false;
    
    actRow = -1;
    
    horizontalHeader()->setVisible(true);
    verticalHeader()->setVisible(true);
    setShowGrid(true);
    setSelectionMode(QAbstractItemView::SingleSelection);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    QObject::connect(automaton, SIGNAL(clearSelection()), this, SLOT(clearSelection()));
    
    switch (type)
    {
        case GRAMMAR_TABLE:
            {
            setSelectionBehavior(QAbstractItemView::SelectRows);
            setColumnCount(2);
            
            QStringList hor;
            hor << trUtf8("Neterminál") << trUtf8("Pravidlo");
            setHorizontalHeaderLabels(hor);
            
            gTable = true;
            QObject::connect(automaton, SIGNAL(selectGrammarRow(int)), this, SLOT(selectRow(int)));
            }
            break;
        case PARSING_TABLE:
            pTable = true;
            QObject::connect(automaton, SIGNAL(selectParsingTableCell(int, int)), this, SLOT(selectCell(int, int)));
            break;
        default:
            {
            setSelectionBehavior(QAbstractItemView::SelectRows);
            setColumnCount(1);
            
            QStringList hor;
            hor << QObject::trUtf8("Zásobník");
            setHorizontalHeaderLabels(hor);
            
            sTable = true;
            // Jen zasobnik behem animace meni svuj obsah.
            // U zasobniku nezvyraznujeme vrchol ani jine radky.
            QObject::connect(&(automaton->getStack()), SIGNAL(changed()), this, SLOT(set()));
            }
            break;
    }
}

void Table::set()
{
    if (gTable)
    {
        automaton->getGrammar().setGrammarTable(*this);
    }
    else if (pTable)
    {
        automaton->getGrammar().setParsingTable(*this);
    }
    else
    {
        automaton->getStack().setStackTable(*this, automaton->getGrammar());
    }
}

void Table::selectRow(int index)
{
    if (gTable)
    {
        changeStyleBack();
        QLabel *label = dynamic_cast<QLabel *>(cellWidget(index, 1));
        label->setStyleSheet("color: white;");
    }
    actRow = index;
    QTableWidget::selectRow(index);
}

void Table::selectCell(int row, int column)
{
    setCurrentCell(row, column);
}

void Table::clearSelection()
{
    QTableWidget::clearSelection();
    changeStyleBack();
    scrollToItem(item(0, 0), QAbstractItemView::PositionAtCenter);
    actRow = -1;
}

void Table::changeStyleBack()
{
    if (actRow >= 0)
    {
        QLabel *label = dynamic_cast<QLabel *>(cellWidget(actRow, 1));
        label->setStyleSheet("color: black;");
    }
}