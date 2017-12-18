#ifndef _TEXT_AREA_HPP
#define _TEXT_AREA_HPP

#include <QPlainTextEdit>
#include <time.h>

class TextArea: public QPlainTextEdit
{
    Q_OBJECT
    
    public:
        TextArea();
        
    public slots:
        void appendHtmlPlainText(bool html, QString htmlPlainText);
        
    private:
        void appendTime(QString &text);
};

#endif