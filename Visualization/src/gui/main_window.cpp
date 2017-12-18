#include "main_window.hpp"

const int MainWindow::MIN_HEIGHT = 690;
const int MainWindow::MIN_WIDTH = 1280;

MainWindow::MainWindow(): QMainWindow(), gTable(GRAMMAR_TABLE, &automaton), dTable(DECOMP_TABLE, &automaton), sTable(STACK_TABLE, &automaton)
{
    setWindowTitle(tr("Vizualizace zpracování zásobníkového automatu"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - MIN_HEIGHT / 2, MIN_WIDTH, MIN_HEIGHT);
    
    createActions();
    createMenu();
    
    control.setObjectName("control");
    processResult(false);
    
    inputLabels.addWidget(&labelDone);
    inputLabels.addWidget(&labelProcess);
    inputLabels.addWidget(&labelFuture);
    labelDone.setObjectName("inputText");
    labelProcess.setObjectName("inputText");
    labelFuture.setObjectName("inputText");
    labelDone.setProperty("value", "done");
    labelProcess.setProperty("value", "processing");
    labelFuture.setProperty("value", "future");
    
    header.addLayout(&inputLabels);
    header.setAlignment(&inputLabels, Qt::AlignLeft);
    header.addWidget(&control);
    header.setAlignment(&control, Qt::AlignRight);
    
    messages.setMaximumHeight(100);
    messages.setReadOnly(true);
    
    QLabel *title = new QLabel(tr("Upravit rychlost"));
    title->setStyleSheet("font-weight: bold; font-size: 20px;");
    slider.setOrientation(Qt::Horizontal);
    slider.setRange(0, 100);
    slider.setValue(40);
    
    stackSlider.addWidget(&sTable);
    stackSlider.addWidget(title);
    stackSlider.addWidget(new QPushButton("Start / Stop"));
    stackSlider.addWidget(new QPushButton("Další krok"));
    stackSlider.addWidget(new QPushButton("Předchozí krok"));
    stackSlider.addWidget(&slider);
    
    QHBoxLayout *tables = new QHBoxLayout();
    tables->setSpacing(5);
    tables->addWidget(&gTable);
    tables->addWidget(&dTable);
    tables->addLayout(&stackSlider);
    
    layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addLayout(&header);
    layout->addLayout(tables);
    layout->addWidget(&messages);
    
    widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    
    connect(&automaton, SIGNAL(message(bool, QString)), this, SLOT(message(bool, QString)));
    connect(&automaton, SIGNAL(processResult(bool)), this, SLOT(processResult(bool)));
    connect(&automaton, SIGNAL(inputChanged(QString, QString, QString)), this, SLOT(inputChanged(QString, QString, QString)));
    automaton.start();
}

MainWindow::~MainWindow()
{
    layout->deleteLater();
    widget->deleteLater();
}

void MainWindow::createActions()
{
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
    
    menu->addAction(aboutAct);
    menu->addSeparator();
    menu->addAction(endAct);
}

void MainWindow::showAbout()
{
    QMessageBox::about(this, tr("O aplikaci"), trUtf8("Aplikace byla vytvořena jako semestrální práce z předmětu KIV/FJP.\nAutor: Michal Horký (A17N0031P)"));
}

void MainWindow::message(bool html, QString message)
{
    messages.appendHtmlPlainText(html, message);
}

void MainWindow::processResult(bool accept)
{
    if (accept)
    {
        control.setProperty("value", "accept");
    }
    else
    {
        control.setProperty("value", "not");
    }
    control.style()->unpolish(&control);
    control.style()->polish(&control);
}

void MainWindow::inputChanged(QString done, QString process, QString future)
{
    labelDone.setText(QString(labelDone.text() + done));
    labelProcess.setText(process);
    labelFuture.setText(future);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    automaton.end();
    automaton.wait();
    event->accept();
}