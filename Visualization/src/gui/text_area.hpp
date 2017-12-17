#ifndef _TEXT_AREA_HPP
#define _TEXT_AREA_HPP

#include <QPlainTextEdit>
#include <QSemaphore>
#include <time.h>

class TextArea: public QPlainTextEdit
{
    Q_OBJECT
    
    public:
        TextArea();
        Qt::CheckState isShown();
        
    public slots:
        void show(int state);
        void appendHtmlPlainText(bool html, QString *htmlPlainText);
        
    private:
        QSemaphore semaphore;
        bool shown;
        void appendTime(QString *text);
};

#endif