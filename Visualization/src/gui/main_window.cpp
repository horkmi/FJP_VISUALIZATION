#include "main_window.hpp"

const int MainWindow::MIN_HEIGHT = 690;
const int MainWindow::MIN_WIDTH = 1280;

MainWindow::MainWindow(): QMainWindow()
{
    setWindowTitle(tr("Vizualizace"));
    
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - MIN_HEIGHT / 2, MIN_WIDTH, MIN_HEIGHT);
    
    createActions();
    createMenu();
    
    messages.setMaximumHeight(100);
    messages.setReadOnly(true);
    
    layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(&messages);
    
    widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    layout->deleteLater();
    widget->deleteLater();
}

void MainWindow::createActions()
{
    helpAct = new QAction(tr("Pomo&c"), this);
    helpAct->setShortcut(tr("Ctrl+H"));
    connect(helpAct, &QAction::triggered, this, &MainWindow::showHelp);
    
    aboutAct = new QAction(tr("&O aplikaci"), this);
    aboutAct->setShortcut(tr("Ctrl+A"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::showAbout);
    
    endAct = new QAction(tr("Kon&ec"), this);
    endAct->setShortcut(tr("Ctrl+Q"));
    connect(endAct, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::createMenu()
{
    menu = menuBar()->addMenu(tr("&Aplikace"));
    
    menu->addAction(helpAct);
    menu->addAction(aboutAct);
    
    menu->addSeparator();
    
    menu->addAction(endAct);
}

void MainWindow::showHelp()
{
    Help *help = new Help(this);
    help->setAttribute(Qt::WA_DeleteOnClose, true);
    help->show();
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, tr("O aplikaci"), trUtf8("Aplikace byla vytvořena jako semestrální práce z předmětu KIV/FJP.\nAutor: Michal Horký (A17N0031P)"));
}

void MainWindow::message(bool html, QString *message)
{
    messages.appendHtmlPlainText(html, message);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // thread.end();
    // thread.wait();
    
    event->accept();
}