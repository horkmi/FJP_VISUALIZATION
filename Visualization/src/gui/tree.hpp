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

class Tree: public QMainWindow
{
    Q_OBJECT
    
    public:
        Tree(QWidget *parent = nullptr);
        ~Tree();
        
        void createNewTree(const QString &dot);
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        static const int MILLI_TIME;
        static const int MAX_STEP_WAITING;
        
        QProcess process;
        
        QTimer *timer;
        int timeCounter;
        
        QImage treeImage;
        QLabel tree;
        QPushButton save;
        
        QScrollArea *scrollArea;
        QVBoxLayout *layout;
        QWidget *widget;
        
        void showImage();
        
    private slots:
        void controlPngExists();
        void saveClicked();
};

#endif