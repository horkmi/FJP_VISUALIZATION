#ifndef _REPORT_H
#define _REPORT_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>

bool confirmDialog(QWidget *parent, const QString &title, const QString &message);
void infoDialog(QWidget *parent, const QString &title, const QString &message);
void errorDialog(QWidget *parent, const QString &title, const QString &message);

#endif