#ifndef _FILE_WORKER_HPP
#define _FILE_WORKER_HPP

#define FILE_GRAMMAR "../data/grammar.txt"
#define FILE_CSS "../css/main.css"

#include <QString>
#include <QFile>

class FileWorker
{
    public:
        static void readGrammar();
        static bool writeGrammar();
        
        static QString *readCSS();
};

#endif