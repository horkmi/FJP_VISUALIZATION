#ifndef _MAIN_WINDOW_HPP
#define _MAIN_WINDOW_HPP

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QLayoutItem>
#include <QResizeEvent>
#include <QSlider>
#include <QPushButton>

#include "help.hpp"
#include "report.hpp"
#include "table.hpp"
#include "text_area.hpp"
#include "../inner/automaton.hpp"

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
        QAction *aboutAct;
        QAction *endAct;
        
        Automaton automaton;
        Table gTable;
        Table dTable;
        Table sTable;
        TextArea messages;
        
        QLabel labelDone;
        QLabel labelProcess;
        QLabel labelFuture;
        QLabel control;
        
        QHBoxLayout header;
        QHBoxLayout inputLabels;
        
        QVBoxLayout stackSlider;
        QSlider slider;
        
        QWidget *widget;
        QVBoxLayout *layout;
        
        void createActions();
        void createMenu();
        
    private slots:
        void showAbout();
        void message(bool html, QString message);
        void processResult(bool accept);
        void inputChanged(QString done, QString process, QString future);
        
    protected:
        void closeEvent(QCloseEvent *event);
};

#endif