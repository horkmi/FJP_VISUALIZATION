#include "text_area.hpp"

TextArea::TextArea(): QPlainTextEdit(), semaphore(1)
{
    shown = true;
    setMaximumBlockCount(100);
}

Qt::CheckState TextArea::isShown()
{
    return shown ? Qt::Checked : Qt::Unchecked;
}

void TextArea::show(int state)
{
    if (state == Qt::Unchecked)
    {
        QPlainTextEdit::hide();
        shown = false;
    }
    else
    {
        QPlainTextEdit::show();
        shown = true;
    }
}

void TextArea::appendHtmlPlainText(bool html, QString *htmlPlainText)
{
    appendTime(htmlPlainText);
    
    semaphore.acquire();
    html ? QPlainTextEdit::appendHtml(*htmlPlainText) : QPlainTextEdit::appendPlainText(*htmlPlainText);
    semaphore.release();
    
    delete htmlPlainText;
}

void TextArea::appendTime(QString *text)
{
    time_t t;
    struct tm tm;
    QString timeStr;
    
    t = time(NULL);
    tm = *localtime(&t);
    
    timeStr.sprintf("%02d:%02d:%02d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
    text->push_front(timeStr);
}
