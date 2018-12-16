#include <QApplication>
#include "gui/main_window.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyleSheet(FileWorker::readCSS());
    
    MainWindow window;
    window.show();
    
    return app.exec();
}