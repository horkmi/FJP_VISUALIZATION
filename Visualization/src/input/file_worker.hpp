#ifndef _FILE_WORKER_HPP
#define _FILE_WORKER_HPP

#define FILE_GRAMMAR "../data/grammar.txt"
#define FILE_CSS "../css/main.css"

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

#include <vector>
using namespace std;

#include "../inner/gram_rule.hpp"

class FileWorker
{
    public:
        static QString loadGrammar(vector<GramRule *> &grammar);
        static bool writeGrammar();
        
        static QString readCSS();
};

#endif