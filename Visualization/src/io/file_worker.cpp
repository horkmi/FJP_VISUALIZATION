#include "file_worker.hpp"

QString FileWorker::getTreeTxtPath()
{
    QFileInfo file(QString(TMP_TREE) + QString(TMP_TREE_TXT));
    return file.absoluteFilePath();
}

QString FileWorker::getTreePngPath()
{
    QFileInfo file(QString(TMP_TREE) + QString(TMP_TREE_PNG));
    return file.absoluteFilePath();
}

bool FileWorker::saveDot(const QString &dot)
{
    return FileWorker::saveFileContent(dot, FileWorker::getTreeTxtPath());
}

bool FileWorker::pngExists()
{
    QFile png(FileWorker::getTreePngPath());
    return png.exists();
}

QImage FileWorker::loadPng()
{
    QImage treeImage;
    treeImage.load(FileWorker::getTreePngPath());
    return treeImage;
}

bool FileWorker::savePng(const QImage &treeImage, QString &dirPath)
{
    QString baseName("tree");
    QString suffix(".png");
    QString imageName(baseName + suffix);
    
    dirPath += "/";
    
    int index = 0;
    while (true)
    {
        QFile file(dirPath + imageName);
        if (!file.exists())
        {
            break;
        }
        else
        {
            imageName = QString(baseName + "_" + QString::number(++index) + suffix);
        }
    }
    
    return treeImage.save(dirPath + imageName, "PNG", 100);
}

bool FileWorker::deleteTmpData()
{
    return QFile::remove(FileWorker::getTreeTxtPath()) & QFile::remove(FileWorker::getTreePngPath());
}

QString FileWorker::readCSS()
{
    return FileWorker::loadFileContent(FILE_CSS);
}

bool FileWorker::saveFileContent(const QString &text, const QString &filePath)
{
    bool results = false;
    
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        results = true;
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        // BEZ BOM!
        stream.setGenerateByteOrderMark(false);
        stream << text;
        stream.flush();
        file.close();
    }
    
    return results;
}

QString FileWorker::loadFileContent(const QString &filePath)
{
    QString results;
    
    QFile file(filePath);
    if (file.open(QFile::ReadOnly | QIODevice::Text))
    {
        results.append(file.readAll());
        file.close();
    }
    
    return results;
}