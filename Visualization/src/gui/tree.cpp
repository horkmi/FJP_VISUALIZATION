#include "tree.hpp"

const int Tree::MIN_HEIGHT = 800;
const int Tree::MIN_WIDTH = 800;
const int Tree::MILLI_TIME = 1000;
const int Tree::MAX_STEP_WAITING = 10;

Tree::Tree(QWidget *parent): QMainWindow(parent)
{
    setWindowTitle(trUtf8("Derivační strom"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - (MIN_HEIGHT / 2 + 40), MIN_WIDTH, MIN_HEIGHT);
    
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(controlPngExists()));
    
    tree.setAlignment(Qt::AlignCenter);
    save.setText(trUtf8("Uložit"));
    QObject::connect(&save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    
    scrollArea = new QScrollArea(this);
    scrollArea->setAlignment(Qt::AlignHCenter);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(&tree);
    
    widget = new QWidget;
    layout = new QVBoxLayout(widget);
    layout->addWidget(scrollArea);
    layout->addWidget(&save);
    setCentralWidget(widget);
}

Tree::~Tree()
{
    timer->stop();
    delete timer;
    widget->deleteLater();
}

void Tree::createNewTree(const QString &dot)
{
    save.setEnabled(false);
    for (int i = 0; i < 3; i++)
    {
        // Zkusit trikrat ulozit soubor s grafem.
        if (FileWorker::saveDot(dot))
        {
            process.start("dot", QStringList() << "-Tpng" << "-O" << FileWorker::getTreeTxtPath());
            timeCounter = 0;
            timer->start(MILLI_TIME);
            break;
        }
    }
}

void Tree::showImage()
{
    treeImage = FileWorker::loadPng();
    tree.setPixmap(QPixmap::fromImage(treeImage));
    FileWorker::deleteTmpData();
    save.setEnabled(true);
    show();
}

void Tree::controlPngExists()
{
    bool pngExists = FileWorker::pngExists();
    if (++timeCounter >= MAX_STEP_WAITING || pngExists)
    {
        timer->stop();
        if (pngExists)
        {
            showImage();
        }
    }
}

void Tree::saveClicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Výběr složky"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
    {
        QString title = trUtf8("Uložení obrázku");
        if (FileWorker::savePng(treeImage, dir))
        {
            infoDialog(this, title, trUtf8("Uložení obrázku proběhlo v pořádku."));
        }
        else
        {
            errorDialog(this, title, trUtf8("Při ukládání obrázku došlo k chybě, zkuste to, prosím, znovu."));
        }
    }
}