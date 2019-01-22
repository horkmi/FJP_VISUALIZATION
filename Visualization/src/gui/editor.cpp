#include "editor.hpp"

const int Editor::MIN_HEIGHT = 500;
const int Editor::MIN_WIDTH = 800;

Editor::Editor(QWidget *parent, const QString &grammarPath): QMainWindow(parent)
{
    this->grammarPath = grammarPath;
    
    setWindowModality(Qt::ApplicationModal);
    setWindowTitle(trUtf8("Úprava gramatiky"));
    setMinimumSize(MIN_WIDTH, MIN_HEIGHT);
    
    QDesktopWidget wid;
    setGeometry((wid.screen()->width() / 2) - MIN_WIDTH / 2, (wid.screen()->height() / 2) - (MIN_HEIGHT / 2 + 40), MIN_WIDTH, MIN_HEIGHT);
    
    createLayout();
}

void Editor::createLayout()
{
    text.insertPlainText(FileWorker::loadFileContent(grammarPath));
    QObject::connect(&text, SIGNAL(textChanged()), this, SLOT(grammarChanged()));
    
    save.setText(trUtf8("Uložit"));
    save.setEnabled(false);
    QObject::connect(&save, SIGNAL(clicked()), this, SLOT(saveClicked()));
    
    widget = new QWidget;
    layout = new QVBoxLayout(widget);
    layout->addWidget(&text);
    layout->addWidget(&save, Qt::AlignVCenter | Qt::AlignRight);
    setCentralWidget(widget);
}

void Editor::grammarChanged()
{
    save.setEnabled(true);
}

void Editor::saveClicked()
{
    QString newGrammar = text.toPlainText().trimmed();
    if (newGrammar.isEmpty())
    {
        errorDialog(this, trUtf8("Chybně zadaná gramatika"), trUtf8("Soubor nesmí být prázdný."));
        return;
    }
    
    short dialogResult = confirmDialogForEditor(this);
    if (dialogResult != 0)
    {
        if (dialogResult > 0)
        {
            QString title = trUtf8("Ukládání gramatiky");
            if (FileWorker::saveFileContent(newGrammar, grammarPath))
            {
                infoDialog(this, title, trUtf8("Gramatika byla v pořádku uložena do původního souboru."));
            }
            else
            {
                errorDialog(this, title, trUtf8("Při ukládání gramatiky do původního souboru došlo k chybě. Zkuste to, prosím, znovu."));
                return;
            }
        }
        emit changeGrammar(newGrammar);
        close();
    }
}