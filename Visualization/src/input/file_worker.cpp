#include "file_worker.hpp"

void FileWorker::readGrammar()
{
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