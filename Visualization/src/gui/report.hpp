#ifndef _REPORT_HPP
#define _REPORT_HPP

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