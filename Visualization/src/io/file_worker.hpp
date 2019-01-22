#ifndef _FILE_WORKER_HPP
#define _FILE_WORKER_HPP

#define FILE_CSS "../css/main.css"

#define TMP_TREE "../data/tmp_tree/"
#define TMP_TREE_TXT "tree.txt"
#define TMP_TREE_PNG "tree.txt.png"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>

#include "../inner/parser.hpp"

class FileWorker
{
    public:
        static QString getTreeTxtPath();
        static bool saveDot(const QString &dot);
        static bool pngExists();
        static QImage loadPng();
        static bool savePng(const QImage &treeImage, QString &dirPath);
        static bool deleteTmpData();
        
        static QString readCSS();
        static bool saveFileContent(const QString &text, const QString &filePath);
        static QString loadFileContent(const QString &filePath);
        
    private:
        static QString getTreePngPath();
};

#endif