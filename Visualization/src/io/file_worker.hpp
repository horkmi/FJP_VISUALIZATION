#ifndef _FILE_WORKER_HPP
#define _FILE_WORKER_HPP

// Soubor s kaskadovymi styly.
#define FILE_CSS "../css/main.css"
// Slozka pro docasne soubory textaku a obrazku derivacniho stromu.
#define TMP_TREE "../data/tmp_tree/"
// Nazev textaku s udaji o derivacnim strome ve formatu DOT.
#define TMP_TREE_TXT "tree.txt"
// Vysledny nazev obrazku derivacniho stromu.
#define TMP_TREE_PNG "tree.txt.png"

#include <QFile>
#include <QFileInfo>
#include <QIODevice>
#include <QImage>
#include <QString>
#include <QTextStream>

/**
 * Instance se nevytvari. Obsahuje pouze staticke funkce pro praci se soubory.
 */ 
class FileWorker
{
    public:
        /**
         * @return cestu k textovemu souboru s derivacnim stromem.
         */                 
        static QString getTreeTxtPath();
        
        /**
         * Ulozi textovy soubor s informace o derivacnim strome.
         * @param const QString &dot - informace o derivacnim strome v DOT formatu.
         * @return jestli se ulozeni povedlo.
         */
        static bool saveDot(const QString &dot);
        
        /**
         * @return jestli obrazek derivacniho stromu existuje.
         */                 
        static bool pngExists();
        
        /**
         * @return obrazek derivacniho stromu.
         */                 
        static QImage loadPng();
        
        /**
         * Ulozi obrazek derivacniho stromu do pozadovane slozky.
         * @param const QImage &treeImage - obrazek derivacniho stromu.
         * @param QString &dirPath - absolutni cesta pozadovane slozky.
         * @return jestli se ulozeni povedlo.                           
         */                 
        static bool savePng(const QImage &treeImage, QString &dirPath);
        
        /**
         * @return jestli se povedlo odstraneni docasnych dat o derivacnim strome.
         */                 
        static bool deleteTmpData();
        
        
        /**
         * @return nactene kaskadove styly pro aplikaci.
         */                 
        static QString readCSS();
        
        /**
         * Ulozi do konkretniho souboru dany text.
         * @param const QString &text - text pro ulozeni.
         * @param const QString &filePath - vybrany soubor (resp. absolutni cesta).
         * @return jestli se text v poradku ulozil.                           
         */                 
        static bool saveFileContent(const QString &text, const QString &filePath);
        
        /**
         * @param const QString &filePath - absolutni cesta vybraneho souboru.
         * @return veskery text z daneho souboru.         
         */                 
        static QString loadFileContent(const QString &filePath);
        
    private:
        /**
         * @return cestu k obrazku s derivacnim stromem.
         */                 
        static QString getTreePngPath();
};

#endif