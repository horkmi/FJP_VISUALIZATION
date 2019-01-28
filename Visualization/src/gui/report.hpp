#ifndef _REPORT_HPP
#define _REPORT_HPP

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>

/**
 * Dialogove okno na ANO, NE.
 * @param QWidget *parent - pointer na rodicovske okno.
 * @param const QString &title - titulek okna.
 * @param const QString &message - zobrazovana zprava.
 * @return jestli uzivatel klikl na ANO. 
 */ 
bool confirmDialog(QWidget *parent, const QString &title, const QString &message);

/**
 * Dialogove okno specialni pro Editor - ulozit do souboru, pouze do aplikace, zrusit.
 * @param QWidget *parent - pointer na rodicovske okno.
 * @return 1 pro ulozeni do souboru, -1 pouze do aplikace, 0 pro zruseni.  
 */ 
short confirmDialogForEditor(QWidget *parent);

/**
 * Informacni dialogove okno.
 * @param QWidget *parent - pointer na rodicovske okno.
 * @param const QString &title - titulek okna.
 * @param const QString &message - zobrazovana zprava. 
 */ 
void infoDialog(QWidget *parent, const QString &title, const QString &message);

/**
 * Chybove dialogove okno.
 * @param QWidget *parent - pointer na rodicovske okno.
 * @param const QString &title - titulek okna.
 * @param const QString &message - zobrazovana zprava. 
 */ 
void errorDialog(QWidget *parent, const QString &title, const QString &message);

#endif