#include "main_window.hpp"

const int MainWindow::MIN_HEIGHT = 690;
const int MainWindow::MIN_WIDTH = 1280;

MainWindow::MainWindow(): QMainWindow(), automaton(Input::DEFAULT_INPUT), gTable(GRAMMAR_TABLE, &automaton), sTable(STACK_TABLE, &automaton), pTable(PARSING_TABLE, &automaton)
{
    setWindowTitle(tr("Vizualizace zpracování zásobníkového automatu"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - MIN_HEIGHT / 2, MIN_WIDTH, MIN_HEIGHT);
    
    speed = 1.0;
    
    createActions();
    createMenu();
    createLayout();
    
    QObject::connect(&automaton, SIGNAL(message(bool, QString)), this, SLOT(message(bool, QString)));
    QObject::connect(&automaton, SIGNAL(processResult(bool)), this, SLOT(processResult(bool)));
    QObject::connect(&automaton, SIGNAL(inputChanged()), this, SLOT(inputChanged()));
    QObject::connect(&automaton, SIGNAL(hasNewHistory()), this, SLOT(automatonHasHistory()));
    QObject::connect(&automaton, SIGNAL(hasNotHistory()), this, SLOT(automatonHasNotHistory()));
    QObject::connect(&automaton, SIGNAL(hasNextStep()), this, SLOT(automatonHasNext()));
    
    input = new Input(this);
    QObject::connect(input, SIGNAL(changeInput(const QString &)), this, SLOT(setInput(const QString &)));
    input->setAttribute(Qt::WA_DeleteOnClose, true);
}

MainWindow::~MainWindow()
{
    input->end();
    input->close();
    
    layout->deleteLater();
    widget->deleteLater();
}

void MainWindow::createActions()
{
    scenariosAct = new QAction(tr("&Scénáře"), this);
    scenariosAct->setShortcut(tr("Ctrl+S"));
    connect(scenariosAct, &QAction::triggered, this, &MainWindow::showScenarios);
    
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
    
    menu->addAction(scenariosAct);
    menu->addSeparator();
    menu->addAction(aboutAct);
    menu->addSeparator();
    menu->addAction(endAct);
}

void MainWindow::createLayout()
{
    // Tlacitka pro urychleni (zpomaleni) animace budou pristupna vzdy (ikdyz animace nebude spustena) - s vyjimkou hranicnich rychlosti.
    playPause.setObjectName("action");
    prev.setObjectName("action");
    next.setObjectName("action");
    reset.setObjectName("action");
    slower.setObjectName("action");
    faster.setObjectName("action");
    playPause.setProperty("button", "play");
    prev.setProperty("button", "prev");
    next.setProperty("button", "next");
    reset.setProperty("button", "reset");
    slower.setProperty("button", "slower");
    faster.setProperty("button", "faster");
    playPause.setCursor(Qt::PointingHandCursor);
    prev.setCursor(Qt::PointingHandCursor);
    next.setCursor(Qt::PointingHandCursor);
    reset.setCursor(Qt::PointingHandCursor);
    slower.setCursor(Qt::PointingHandCursor);
    faster.setCursor(Qt::PointingHandCursor);
    QObject::connect(&playPause, SIGNAL(clicked()), this, SLOT(playPauseAnimation()));
    QObject::connect(&prev, SIGNAL(clicked()), this, SLOT(prevStep()));
    QObject::connect(&next, SIGNAL(clicked()), this, SLOT(nextStep()));
    QObject::connect(&reset, SIGNAL(clicked()), this, SLOT(resetAnimation()));
    QObject::connect(&slower, SIGNAL(clicked()), this, SLOT(slowDown()));
    QObject::connect(&faster, SIGNAL(clicked()), this, SLOT(speedUp()));
    buttonScenarioNoGrammar();
    
    visualizationSpeed.setAlignment(Qt::AlignCenter);
    visualizationSpeed.setStyleSheet("font-weight: bold; max-width: 100px;");
    setSpeedLabel();
    
    leftHeader.setMargin(0);
    leftHeader.setSpacing(15);
    leftHeader.setAlignment(Qt::AlignLeft);
    leftHeader.addWidget(&playPause);
    leftHeader.addWidget(&prev);
    leftHeader.addWidget(&next);
    leftHeader.addWidget(&reset);
    
    results.setAlignment(Qt::AlignCenter);
    results.setObjectName("control");
    resetResults();
    
    rightHeader.setMargin(0);
    rightHeader.setAlignment(Qt::AlignRight);
    rightHeader.addWidget(&slower);
    rightHeader.addWidget(&visualizationSpeed);
    rightHeader.addWidget(&faster);
    
    header = new QHBoxLayout();
    header->addLayout(&leftHeader, Qt::AlignLeft);
    header->addWidget(&results, Qt::AlignCenter);
    header->addLayout(&rightHeader, Qt::AlignRight);
    
    
    
    // Tlacitko pro upraveni vstupu bude pristupne vzdy.
    // Nikdy nebude vlozen prazdny retezec.
    inputSetter.setObjectName("action");
    inputSetter.setProperty("button", "input");
    inputSetter.setCursor(Qt::PointingHandCursor);
    QObject::connect(&inputSetter, SIGNAL(clicked()), this, SLOT(updateInput()));
    processing.setObjectName("inputText");
    processingLayout.addWidget(&inputSetter);
    scrollProcessing = new QScrollArea(this);
    scrollProcessing->setMaximumHeight(74);
    scrollProcessing->setMinimumHeight(74);
    scrollProcessing->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollProcessing->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollProcessing->setWidget(&processing);
    processingLayout.addWidget(scrollProcessing);
    // Zavolat manualne pro spravnost pocatecniho vzhledu.
    inputChanged();
    setProcessingWidth();
    
    
    
    fileTitle.setText("Výběr souboru");
    fileTitle.setObjectName("titleText");
    filePath.setText("Cesta ke gramatice");
    filePath.setStyleSheet("color: grey;");
    filePath.setAlignment(Qt::AlignVCenter | Qt::AlignRight);
    chooseFile.setObjectName("action");
    chooseFile.setProperty("button", "choose");
    chooseFile.setCursor(Qt::PointingHandCursor);
    QObject::connect(&chooseFile, SIGNAL(clicked()), this, SLOT(chooseGrammar()));
    fileChooserLayout.setMargin(0);
    fileChooserLayout.setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    fileChooserLayout.addWidget(&chooseFile);
    fileChooserLayout.addWidget(&filePath);
    fileLayout = new QVBoxLayout();
    fileLayout->setSpacing(10);
    fileLayout->addWidget(&fileTitle);
    fileLayout->addLayout(&fileChooserLayout);
    
    
    gTitle.setText("Gramatika");
    gTitle.setObjectName("titleText");
    gUpdate.setObjectName("action");
    gUpdate.setProperty("button", "edit");
    gUpdate.setCursor(Qt::PointingHandCursor);
    gUpdate.setEnabled(false);
    QObject::connect(&gUpdate, SIGNAL(clicked()), this, SLOT(editGrammar()));
    gTitleLayout.setMargin(0);
    gTitleLayout.addWidget(&gTitle, Qt::AlignLeft);
    gTitleLayout.addWidget(&gUpdate, Qt::AlignRight);
    gLayout = new QVBoxLayout();
    gLayout->setSpacing(10);
    gLayout->addLayout(&gTitleLayout);
    gLayout->addWidget(&gTable);
    
    
    sTitle.setText("Zásobník");
    sTitle.setObjectName("titleText");
    sLayout.setSpacing(10);
    sLayout.addWidget(&sTitle);
    sLayout.addWidget(&sTable);
    
    QWidget *wLeftBody = new QWidget;
    wLeftBody->setMaximumWidth(350);
    leftBody = new QVBoxLayout(wLeftBody);
    leftBody->setMargin(0);
    leftBody->setSpacing(20);
    leftBody->addLayout(fileLayout);
    leftBody->addLayout(gLayout);
    leftBody->addLayout(&sLayout);
    
    
    
    pTitle.setText("Tabulka přechodů");
    pTitle.setObjectName("titleText");
    pLayout.addWidget(&pTitle);
    pLayout.addWidget(&pTable);
    
    
    body = new QHBoxLayout();
    body->addWidget(wLeftBody);
    body->addLayout(&pLayout);
    
    
    
    messages.setMaximumHeight(150);
    
    layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addLayout(header);
    layout->addLayout(&processingLayout);
    layout->addLayout(body);
    layout->addWidget(&messages);
    
    widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
}

void MainWindow::playPauseAnimation()
{
    if (playPause.property("button") == QVariant("play"))
    {
        // Spustit prehravani (zmena ikony na pause).
        automaton.play();
        buttonScenarioAnimation();
    }
    else
    {
        // Nastavit pauzu (zmena ikona na play).
        automaton.pause();
        buttonScenarioOkGrammar();
    }
}

void MainWindow::prevStep()
{
    automaton.prevStep();
}

void MainWindow::nextStep()
{
    automaton.nextStep();
}

void MainWindow::resetAnimation()
{
    automaton.reset();
    resetResults();
    messages.clear();
    buttonScenarioOkGrammar();
}

void MainWindow::slowDown()
{
    // Zpomaleni animace.
    speed -= 0.1;
    automaton.changeWaiting(speed);
    
    faster.setEnabled(true);
    if (speed < 0.6)
    {
        slower.setEnabled(false);
    }
    
    setSpeedLabel();
}

void MainWindow::speedUp()
{
    // Zrychleni animace.
    speed += 0.1;
    automaton.changeWaiting(speed);
    
    slower.setEnabled(true);
    if (speed >= 2)
    {
        faster.setEnabled(false);
    }
    
    setSpeedLabel();
}

void MainWindow::updateInput()
{
    input->show();
}

void MainWindow::setInput(const QString &input)
{
    // Nejdrive ukoncit pripadne bezici animaci.
    resetAnimation();
    automaton.setInput(input);
    inputChanged();
    setProcessingWidth();
}

void MainWindow::setProcessingWidth()
{
    QTextDocument text;
    text.setHtml(processing.text());
    int widthAll = processing.fontMetrics().boundingRect(text.toPlainText()).width() + 20;
    processing.setMinimumWidth(widthAll);
    processing.setMaximumWidth(widthAll);
}

void MainWindow::chooseGrammar()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Vyberte soubor s gramatikou"), "../data", tr("Text files (*.txt)"));
    if (!fileName.isEmpty())
    {
        QString grammar = FileWorker::loadFileContent(fileName);
        if (!grammar.isEmpty())
        {
            // Jakmile je vybrana nejaka gramatika (i se spatnym formatem) zpristupnit tlacitko pro jeji upravu.
            // Tlacitko po prvnim zpristupneni uz nema smysl ukryvat - vzdy bude nactena nejaka gramatika.
            gUpdate.setEnabled(true);
            filePath.setText(fileName);
            setGrammar(grammar);
        }
        else
        {
            errorDialog(this, trUtf8("Načtení gramatiky"), trUtf8("Při načítání souboru s gramatikou došlo k chybě - zkuste to, prosím, znovu (soubor nesmí být prázdný)."));
        }
    }
}

void MainWindow::editGrammar()
{
    Editor *editor = new Editor(this, filePath.text());
    QObject::connect(editor, SIGNAL(changeGrammar(const QString &)), this, SLOT(setGrammar(const QString &)));
    editor->setAttribute(Qt::WA_DeleteOnClose, true);
    editor->show();
}

void MainWindow::setGrammar(const QString &grammar)
{
    // Nejdrive ukoncit pripadne bezici animaci.
    resetAnimation();
    gTable.setRowCount(0);
    pTable.setRowCount(0);
    
    QString title = trUtf8("Načtení gramatiky");
    if (Parser::parseGrammar(automaton.getGrammar(), grammar))
    {
        if (automaton.getGrammar().isCorrect())
        {
            gTable.set();
            sTable.set();
            pTable.set();
            infoDialog(this, title, trUtf8("Načtení gramatiky proběhlo v pořádku, vybraná gramatika je LL(1)."));
        }
        else
        {
            buttonScenarioNoGrammar();
            errorDialog(this, title, trUtf8("Vybraná gramatika není LL(1)."));
        }
    }
    else
    {
        buttonScenarioNoGrammar();
        errorDialog(this, title, trUtf8("Vybraná gramatika má špatný formát."));
    }
}

void MainWindow::showScenarios()
{
    infoDialog(this, trUtf8("Scénáře"), trUtf8("V pracovním adresáři aplikace je adresář data. V něm jsou ukázky gramatik.<br /><br />") +
                                           trUtf8("<b><i><u>Akceptovatelné řetězce</u></i></b><br />") +
                                           trUtf8("00 - 02: \"<b>a b b a b</b>\"<br />") +
                                           trUtf8("03: \"<b>d d b c c c c</b>\"<br />") +
                                           trUtf8("04: \"<b>1 1 a 0 0</b>\"<br />") +
                                           trUtf8("06: \"<b>a a c b b</b>\"<br />") +
                                           trUtf8("07: \"<b>a c a a</b>\"<br />") +
                                           trUtf8("08: \"<b>[ [ [ ] ] [ ] ]</b>\"<br />") +
                                           trUtf8("09: \"<b>a + a</b>\"<br />") +
                                           trUtf8("11: \"<b>n + n * n</b>\"<br />") +
                                           trUtf8("12: \"<b>( terminál plus terminál ) násobení terminál</b>\"<br />"));
}

void MainWindow::showAbout()
{
    infoDialog(this, tr("O aplikaci"), trUtf8("Aplikace byla vytvořena jako semestrální práce z předmětu KIV/FJP.\nAutor: Michal Horký (A18N0087P)"));
}

void MainWindow::message(bool html, QString message)
{
    messages.appendHtmlPlainText(html, message);
}

void MainWindow::setSpeedLabel()
{
    visualizationSpeed.setText("Rychlost: <i>" + QString::number(speed, 'f', 1) + "x</i>");
}

void MainWindow::resetResults()
{
    results.setProperty("value", "processing");
    results.setText("---");
    results.style()->unpolish(&results);
    results.style()->polish(&results);
}

void MainWindow::processResult(bool accept)
{
    buttonScenarioOkGrammar();
    playPause.setEnabled(false);
    next.setEnabled(false);
    if (accept)
    {
        results.setProperty("value", "accept");
        results.setText(trUtf8("AKCEPTOVÁNO"));
        tree.createNewTree(automaton.getGrammar().toDotLanguage(automaton.getDonePart(), automaton.getResultingRules()));
    }
    else
    {
        results.setProperty("value", "not");
        results.setText(trUtf8("NEAKCEPTOVÁNO"));
    }
    results.style()->unpolish(&results);
    results.style()->polish(&results);
    emit message(false, results.text());
}

void MainWindow::inputChanged()
{
    processing.setText("<span style=\"color: #07A005;\">" + automaton.getDonePart() + "</span> " +
                       "<span style=\"font-style: italic; color: #FF9E00;\">" + automaton.getProcessingPart() + "</span> " +
                       "<span style=\"color: #D30000;\">" + automaton.getWaitingPart() + "</span>");
    
    if (gTable.rowCount() < 1)
    {
        buttonScenarioNoGrammar();
    }
    
    int widthDone = processing.fontMetrics().boundingRect(automaton.getDonePart()).width() + 10;
    int widthProcessing = processing.fontMetrics().boundingRect(automaton.getProcessingPart()).width() + 10;
    
    double centerProcessing = widthDone + widthProcessing / 2.0;
    double centerView = scrollProcessing->viewport()->contentsRect().width() / 2.0;
    scrollProcessing->horizontalScrollBar()->setValue(static_cast<int>(centerProcessing - centerView));
}

void MainWindow::buttonScenarioNoGrammar()
{
    // Nebyla vybrana gramatika nebo ma text, predstavujici gramatiku, spatny format.
    setPlayPauseView(true); // Muze byt prerusena animace.
    playPause.setEnabled(false);
    prev.setEnabled(false);
    next.setEnabled(false);
    reset.setEnabled(false);
}

void MainWindow::buttonScenarioOkGrammar()
{
    // Gramatika byla v poradku nactena.
    setPlayPauseView(true); // Muze byt prerusena animace.
    playPause.setEnabled(true);
    prev.setEnabled(automaton.hasHistory());
    next.setEnabled(true);
    reset.setEnabled(true);
}

void MainWindow::buttonScenarioAnimation()
{
    setPlayPauseView(false); // Prave byla spustena animace - nastavit tlacitko na pausu.
    prev.setEnabled(false);
    next.setEnabled(false);
}

void MainWindow::setPlayPauseView(bool play)
{
    bool styleUpdate = false;
    
    bool actPlayView = playPause.property("button") == QVariant("play");
    if (play && !actPlayView)
    {
        styleUpdate = true;
        playPause.setProperty("button", "play");
    }
    else if (!play && actPlayView)
    {
        styleUpdate = true;
        playPause.setProperty("button", "pause");
    }
    
    if (styleUpdate)
    {
        playPause.style()->unpolish(&playPause);
        playPause.style()->polish(&playPause);
        playPause.update();
    }
}

void MainWindow::automatonHasHistory()
{
    prev.setEnabled(true);
}

void MainWindow::automatonHasNotHistory()
{
    prev.setEnabled(false);
}

void MainWindow::automatonHasNext()
{
    // V pripade, kdy se uzivatel vraci v krocich zpet (nemuze byt nic rozhodnuto a automaticky musi byt uvolneno tlacitko pro krok dale a prehravani).
    resetResults();
    playPause.setEnabled(true);
    next.setEnabled(true);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
}