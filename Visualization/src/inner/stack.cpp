#include "stack.hpp"

void Stack::append(Rule rule)
{
    for (int i = rule.getRule().size() - 1; i >= 0; i--)
    {
        stack.push(rule.getRule().at(i));
    }
    
    if (rule.getRule().size() > 0)
    {
        emit changed();
    }
}

void Stack::push(int value)
{
    stack.push(value);
    emit changed();
}

int Stack::pop(int count)
{
    int value;
    do
    {
        value = stack.pop();
    }
    while (--count > 0);
    emit changed();
    return value;
}

bool Stack::isEmpty()
{
    return stack.isEmpty();
}

void Stack::clear()
{
    stack.clear();
    emit changed();
}

void Stack::setStackTable(QTableWidget &table, Grammar &grammar)
{
    table.setRowCount(stack.size());
    
    QStringList ver;
    for (int i = 0; i < stack.size(); i++)
    {
        if (i == 0)
        {
            ver << QObject::trUtf8("Vrchol");
        }
        else
        {
            ver << QString(QString::number(i + 1) + ". prvek");
        }
    }
    table.setVerticalHeaderLabels(ver);
    
    for (int i = 0; i < stack.size(); i++)
    {
        QLabel *label = new QLabel(grammar.indexToString(stack.at(i)));
        label->setObjectName("grammar_table");
        label->setProperty("value", "rule");
        table.setCellWidget(stack.size() - i - 1, 0, label);
    }
}

QString Stack::toString(Grammar &grammar)
{
    QString results;
    for (int i = stack.size() - 1; i >= 0; i--)
    {
        if (i != stack.size() - 1)
        {
            results.append(" ");
        }
        results.append(grammar.getWord(stack.at(i)));
    }
    return results;
}