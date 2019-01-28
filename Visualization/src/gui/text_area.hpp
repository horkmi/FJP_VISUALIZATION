#ifndef _TEXT_AREA_HPP
#define _TEXT_AREA_HPP

#include <QPlainTextEdit>
#include <time.h>

/**
 * Instance predstavuje textovou oblast pro vypis aktualniho stavu zpracovani.
 */ 
class TextArea: public QPlainTextEdit
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavi maximalni pocet radku.
         */                 
        TextArea();
        
    public slots:
        /**
         * Vlozi do textove oblasti dany text.
         * @param bool html - jestli jsou v textu HTML atributy.
         * @param QString htmlPlainText - text, ktery ma byt vlozen.
         */                 
        void appendHtmlPlainText(bool html, QString htmlPlainText);
        
    private:
        /**
         * Funkce pro pridani casove informace.
         * @param QString &text - text, do ktereho se ma pridat cas.         
         */                 
        void appendTime(QString &text);
};

#endif