#ifndef _MAIN_WINDOW_HPP
#define _MAIN_WINDOW_HPP

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QLayoutItem>
#include <QResizeEvent>

#include "help.hpp"
#include "report.hpp"
#include "text_area.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT
    
    public:
        MainWindow();
        ~MainWindow();
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        
        QMenu *menu;
        QAction *helpAct;
        QAction *aboutAct;
        QAction *endAct;
        
        TextArea messages;
        
        QWidget *widget;
        QVBoxLayout *layout;
        
        void createActions();
        void createMenu();
        
    private slots:
        void showHelp();
        void showAbout();
        void message(bool html, QString *message);
        
    protected:
        void closeEvent(QCloseEvent *event);
};

#endif