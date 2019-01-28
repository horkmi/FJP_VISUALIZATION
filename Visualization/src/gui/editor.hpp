#ifndef _EDITOR_HPP
#define _EDITOR_HPP

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QDesktopWidget>

#include "report.hpp"
#include "../io/file_worker.hpp"

/**
 * Instance predstavuje okno pro upravu gramatiky.
 */ 
class Editor: public QMainWindow
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavuje okno a vola funkci pro vytvoreni layoutu.
         * @param QWidget *parent - pointer na rodice.
         * @param const QString &grammarPath - absolutni cesta k upravovane gramatice.         
         */                 
        Editor(QWidget *parent, const QString &grammarPath);
        
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
         * Absolutni cesta upravovane gramatiky.
         */                 
        QString grammarPath;
        
        /**
         * Textova oblast pro upravu gramatiky.
         */                 
        QPlainTextEdit text;
        
        /**
         * Tlacitko pro ulozeni upravene gramatiky.
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
         */                 
        void createLayout();
        
    private slots:
        /**
         * V pripade zmeny textu v textove oblasti je vyvolan tento slot, ktery
         * zpristupnuje tlacitko ulozit.
         */                 
        void grammarChanged();
        
        /**
         * Pri reakci na kliknuti tlacitka ulozit, provede ulozeni gramatiky.
         */                 
        void saveClicked();
        
    signals:
        /**
         * Signal s informaci pro aplikaci, ze doslo ke zmene gramatiky.
         * @param const QString &grammar - zmeneny hruby text gramatiky.
         */                 
        void changeGrammar(const QString &grammar);
};

#endif