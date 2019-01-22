#include "report.hpp"

bool confirmDialog(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox box(parent);
    box.setWindowTitle(title);
    box.setText(message);
    box.setIcon(QMessageBox::Question);
    
    QAbstractButton *yes = box.addButton(QObject::trUtf8("Ano"), QMessageBox::YesRole);
    box.addButton(QObject::trUtf8("Ne"), QMessageBox::NoRole);
    
    box.exec();
    return box.clickedButton() == yes;
}

short confirmDialogForEditor(QWidget *parent)
{
    QMessageBox box(parent);
    box.setWindowTitle(QObject::trUtf8("Uložení gramatiky"));
    box.setText(QObject::trUtf8("Gramatika byla upravena. Vyberte jednu z možností uložení."));
    box.setIcon(QMessageBox::Question);
    
    QAbstractButton *toFile = box.addButton(QObject::trUtf8("Přepsat soubor"), QMessageBox::YesRole);
    QAbstractButton *toApp = box.addButton(QObject::trUtf8("Pouze pro aplikaci"), QMessageBox::AcceptRole);
    box.addButton(QObject::trUtf8("Neukládat"), QMessageBox::NoRole);
    
    box.exec();
    
    short result = 0;
    if (box.clickedButton() == toFile)
    {
        result = 1;
    }
    else if (box.clickedButton() == toApp)
    {
        result = -1;
    }
    
    return result;
}

void infoDialog(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox::information(parent, title, message, QMessageBox::Ok);
}

void errorDialog(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox::critical(parent, title, message, QMessageBox::Ok);
}