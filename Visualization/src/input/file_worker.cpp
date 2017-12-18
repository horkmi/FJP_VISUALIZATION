#include "file_worker.hpp"

QString FileWorker::loadGrammar(vector<GramRule *> &grammar)
{
    while (!grammar.empty())
    {
        delete grammar.back();
        grammar.pop_back();
    }
    
    QString start;
    bool firstLine = true;
    
    QFile file(FILE_GRAMMAR);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream input(&file);
        
        QString line = input.readLine();
        while (!line.isNull())
        {
            if (firstLine)
            {
                start = line;
                firstLine = false;
            }
            else
            {
                QStringList parts = line.split("\t");
                grammar.push_back(new GramRule(parts.at(0), parts.at(1)));
            }
            line = input.readLine();
        }
    }
    
    /*
    vector<GramRule *>::iterator i;
    for (i = grammar.begin(); i != grammar.end(); i++)
    {
        printf("%s --> %s\n", (*i)->nonterminal.toUtf8().data(), (*i)->prodRule.toUtf8().data());
    }
    printf("Startovni symbol je %s\n", start.toUtf8().data());
    */
    
    return start;
}

bool FileWorker::writeGrammar()
{
    return true;
}

QString *FileWorker::readCSS()
{
    QString *result = new QString();
    
    QFile file(FILE_CSS);
    if (file.open(QFile::ReadOnly))
    {
        result->append(QLatin1String(file.readAll()));
    }
    
    return result;
}