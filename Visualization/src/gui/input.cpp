#include "input.hpp"

const QString Input::DEFAULT_INPUT = trUtf8("Kliknutím na tužku nastavíte vstupní text...");
const int Input::MIN_HEIGHT = 400;
const int Input::MIN_WIDTH = 800;

Input::Input(QWidget *parent): QMainWindow(parent)
{
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle(trUtf8("Upravit vstup"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - (MIN_HEIGHT / 2 + 40), MIN_WIDTH, MIN_HEIGHT);
    
    createLayout(DEFAULT_INPUT);
    active = true;
}

void Input::end()
{
    active = false;
}

void Input::createLayout(const QString &input)
{
    this->input.insertPlainText(input);
    
    save.setText(trUtf8("Nastavit"));
    QObject::connect(&save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    
    widget = new QWidget;
    layout = new QVBoxLayout(widget);
    layout->addWidget(&(this->input));
    layout->addWidget(&save);
    setCentralWidget(widget);
}

void Input::saveClicked()
{
    QString text = input.toPlainText().trimmed().replace('\n', ' ');
    if (text.isEmpty())
    {
        errorDialog(this, trUtf8("Chyba při zadávání"), trUtf8("Vstupní řetězec nesmí být prázdný."));
    }
    else
    {
        emit changeInput(text);
        close();
    }
}

void Input::closeEvent(QCloseEvent *event)
{
    if (active)
    {
        event->ignore();
        hide();
    }
    else
    {
        event->accept();
    }
}