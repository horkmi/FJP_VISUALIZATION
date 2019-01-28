#ifndef _INPUT_HPP
#define _INPUT_HPP

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QDesktopWidget>
#include <QCloseEvent>

#include "report.hpp"

/**
 * Instance predstavuje okno pro upravu vstupniho textu.
 */ 
class Input: public QMainWindow
{
    Q_OBJECT
    
    public:
        /**
         * Defaultni vstupni text.
         */                 
        static const QString DEFAULT_INPUT;
        
        /**
         * Konstruktor nastavuje okno a vola funkci pro vytvoreni layoutu.
         * @param QWidget *parent - pointer na rodice.
         */                 
        Input(QWidget *parent);
        
        /**
         * Funkce nastavujici atribut active na false. Volano pri ukoncovani aplikace.
         */                 
        void end();
        
    protected:
        /**
         * Funkce vyvolana pri zavirani okna.
         * @param QCloseEvent *event - vyvolana udalost.         
         */                 
        void closeEvent(QCloseEvent *event);
        
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
         * Jestli je aplikace aktivni. Pokud ne, pri zavreni okna ho opravdu zavrit,
         * ne jenom skryt.         
         */                 
        bool active;
        
        /**
         * Textova oblast pro upravu vstupniho textu.
         */                 
        QPlainTextEdit input;
        
        /**
         * Tlacitko pro ulozeni upraveneho vstupniho textu.
         */                 
        QPushButton save;
        
        /**
         * Hlavni layout.
         */                 
        QVBoxLayout *layout;
        
        /**
         * Widget hlavniho layoutu.
         */                 
        QWidget *widget;
        
        /**
         * Vytvori layout okna.
         * @param const QString &input - aktualni vstupni text.         
         */                 
        void createLayout(const QString &input);
        
    private slots:
        /**
         * Pri reakci na kliknuti tlacitka ulozit, provede ulozeni vstupniho textu.
         */                 
        void saveClicked();
        
    signals:
        /**
         * Signal s informaci pro aplikaci, ze doslo ke zmene vstupniho textu.
         * @param const QString &input - zmeneny vstupni text.
         */                 
        void changeInput(const QString &input);
};

#endif