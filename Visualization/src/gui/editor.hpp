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

class Editor: public QMainWindow
{
    Q_OBJECT
    
    public:
        Editor(QWidget *parent, const QString &grammarPath);
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        
        QString grammarPath;
        QPlainTextEdit text;
        QPushButton save;
        
        QVBoxLayout *layout;
        QWidget *widget;
        
        void createLayout();
        
    private slots:
        void grammarChanged();
        void saveClicked();
        
    signals:
        void changeGrammar(const QString &grammar);
};

#endif