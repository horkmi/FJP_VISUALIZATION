#include <QApplication>
#include "gui/main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QString *css = FileWorker::readCSS();
    app.setStyleSheet(*css);
    delete css;
    
    MainWindow window;
    window.show();
    
    return app.exec();
}