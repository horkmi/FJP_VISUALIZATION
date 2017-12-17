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

void infoDialog(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox::information(parent, title, message, QMessageBox::Ok);
}

void errorDialog(QWidget *parent, const QString &title, const QString &message)
{
    QMessageBox::critical(parent, title, message, QMessageBox::Ok);
}