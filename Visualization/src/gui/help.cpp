#include "help.hpp"

const int Help::MIN_HEIGHT = 500;
const int Help::MIN_WIDTH = 800;

Help::Help(QWidget *parent): QMainWindow(parent)
{
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - (MIN_HEIGHT / 2 + 40), MIN_WIDTH, MIN_HEIGHT);
    
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle(trUtf8("Nápověda"));
    
    widget = new QWidget;
    setCentralWidget(widget);
    
    layout = new QVBoxLayout(widget);
}

Help::~Help()
{
    layout->deleteLater();
    widget->deleteLater();
}