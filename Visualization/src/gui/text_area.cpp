#include "text_area.hpp"

TextArea::TextArea(): QPlainTextEdit()
{
    setMaximumBlockCount(100);
}

void TextArea::appendHtmlPlainText(bool html, QString htmlPlainText)
{
    appendTime(htmlPlainText);
    html ? QPlainTextEdit::appendHtml(htmlPlainText) : QPlainTextEdit::appendPlainText(htmlPlainText);
}

void TextArea::appendTime(QString &text)
{
    time_t t;
    struct tm tm;
    QString timeStr;
    
    t = time(NULL);
    tm = *localtime(&t);
    
    timeStr.sprintf("%02d:%02d:%02d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
    text.push_front(timeStr);
}
