#ifndef _TREE_HPP
#define _TREE_HPP

#include <QMainWindow>
#include <QDesktopWidget>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPushButton>
#include <QTimer>
#include <QProcess>
#include <QFileDialog>
#include <QScrollArea>
#include <QDebug>

#include "report.hpp"
#include "../io/file_worker.hpp"

/**
 * Instance predstavuje okno s obrazkem derivacniho stromu.
 */ 
class Tree: public QMainWindow
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavuje layout.
         * @param QWidget *parent - pointer na rodice, defaultne nullptr.
         */                 
        Tree(QWidget *parent = nullptr);
        
        /**
         * Zastavi casovac a uvolni pamet jemu alokovanou. Navic zavola funkci pro
         * uvolneni pameti po layoutu (jen pro jistotu).         
         */                 
        ~Tree();
        
        /**
         * Ulozi strom do souboru, spusti prikaz, nasledne casovac, ktery ceka, jestli
         * se objevi obrazek stromu.
         * @param const QString &dot - strom v DOT formatu.
         */                 
        void createNewTree(const QString &dot);
        
    private:
        /**
         * Minimalni vyska okna.
         */                 
        static const int MIN_HEIGHT;
        
        /**
         * Minimalni sirka okna.
         */                 
        static const int MIN_WIDTH;
        
        /**
         * Cas uspani casovace.
         */                 
        static const int MILLI_TIME;
        
        /**
         * Maximalni pocet uspavacich cyklu casovace.
         */                 
        static const int MAX_STEP_WAITING;
        
        /**
         * Proces, ktery spousti prikaz dot pro vytvoreni obrazku derivacniho stromu.
         */                 
        QProcess process;
        
        /**
         * Casovac pro kontrolu existence vygenerovaneho obrazku.
         */                 
        QTimer *timer;
        
        /**
         * Citac uspavacich cyklu.
         */                 
        int timeCounter;
        
        /**
         * Obrazek derivacniho stromu.
         */                 
        QImage treeImage;
        
        /**
         * Label, do ktereho se ulozi pixmapa obrazku.
         */         
        QLabel tree;
        
        /**
         * Tlacitko pro ulozeni obrazku.
         */                 
        QPushButton save;
        
        /**
         * Obrazek musi byt ve skrolovaci oblasti kvuli je velikosti.
         */                 
        QScrollArea *scrollArea;
        
        /**
         * Hlavni layout.
         */                 
        QVBoxLayout *layout;
        
        /**
         * Widget hlavniho layoutu.
         */                 
        QWidget *widget;
        
        /**
         * Funkce, ktera nacte obrazek, ulozi pixmapu a zobrazi cele okno.
         */                 
        void showImage();
        
    private slots:
        /**
         * Kontrola existence obrazku.
         */                 
        void controlPngExists();
        
        /**
         * Reakce na stisk tlacitka ulozit.
         */                 
        void saveClicked();
};

#endif