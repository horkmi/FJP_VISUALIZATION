#ifndef _HELP_HPP
#define _HELP_HPP

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDesktopWidget>

class Help: public QMainWindow
{
    Q_OBJECT
    
    public:
        Help(QWidget *parent = 0);
        ~Help();
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        
        QWidget *widget;
        QVBoxLayout *layout;
};

#endif