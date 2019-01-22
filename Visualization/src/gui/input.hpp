#ifndef _INPUT_HPP
#define _INPUT_HPP

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDesktopWidget>

#include "report.hpp"

class Input: public QMainWindow
{
    Q_OBJECT
    
    public:
        Input(QWidget *parent, const QString &input);
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        
        QLineEdit input;
        QPushButton save;
        
        QHBoxLayout *layout;
        QWidget *widget;
        
        void createLayout(const QString &input);
        
    private slots:
        void saveClicked();
        
    signals:
        void changeInput(const QString &input);
};

#endif