#ifndef _MAIN_WINDOW_HPP
#define _MAIN_WINDOW_HPP

#include <QMenuBar>
#include <QAction>
#include <QMenu>
#include <QLayoutItem>
#include <QResizeEvent>
#include <QSlider>
#include <QPushButton>
#include <QFileDialog>
#include <QTextDocument>

#include "tree.hpp"
#include "editor.hpp"
#include "input.hpp"
#include "report.hpp"
#include "table.hpp"
#include "text_area.hpp"
#include "../inner/automaton.hpp"

class MainWindow: public QMainWindow
{
    Q_OBJECT
    
    public:
        MainWindow();
        ~MainWindow();
        
    private:
        static const int MIN_HEIGHT;
        static const int MIN_WIDTH;
        
        Automaton automaton;
        double speed;
        
        Tree tree;
        
        QMenu *menu;
        QAction *scenariosAct;
        QAction *aboutAct;
        QAction *endAct;
        
        QPushButton playPause;
        QPushButton prev;
        QPushButton next;
        QPushButton reset;
        QPushButton slower;
        QLabel visualizationSpeed;
        QPushButton faster;
        QHBoxLayout leftHeader;
        QLabel results;
        QHBoxLayout rightHeader;
        QHBoxLayout *header;
        
        QPushButton inputSetter;
        QLabel processing;
        QHBoxLayout processingLayout;
        
        QLabel fileTitle;
        QLabel filePath;
        QPushButton chooseFile;
        QHBoxLayout fileChooserLayout;
        QVBoxLayout *fileLayout;
        
        QLabel gTitle;
        QPushButton gUpdate;
        QHBoxLayout gTitleLayout;
        Table gTable;
        QVBoxLayout *gLayout;
        
        QLabel sTitle;
        Table sTable;
        QVBoxLayout sLayout;
        
        QVBoxLayout *leftBody;
        
        QLabel pTitle;
        Table pTable;
        QVBoxLayout pLayout;
        
        QHBoxLayout *body;
        
        TextArea messages;
        
        QWidget *widget;
        QVBoxLayout *layout;
        
        void createActions();
        void createMenu();
        void createLayout();
        
        void resetResults();
        void setSpeedLabel();
        
        void buttonScenarioNoGrammar(); // Nebyla vybrana gramatika nebo ma text, predstavujici gramatiku, spatny format.
        void buttonScenarioOkGrammar(); // Gramatika byla v poradku nactena.
        void buttonScenarioAnimation(); // Je spustena animace zpracovani.
        /**
         * @param bool play - true kdyz se ma nastavit sipka pro prehravani.
         */
        void setPlayPauseView(bool play);
        
    private slots:
        void automatonHasHistory();
        void automatonHasNotHistory();
        void automatonHasNext();
        
        void playPauseAnimation();
        void prevStep();
        void nextStep();
        void resetAnimation();
        void slowDown();
        void speedUp();
        void updateInput();
        void setInput(const QString &input);
        void chooseGrammar();
        void editGrammar();
        void setGrammar(const QString &grammar); // Pro chooseGrammar() a editGrammar()!
        
        void showScenarios();
        void showAbout();
        void message(bool html, QString message);
        void processResult(bool accept);
        void inputChanged();
        
    protected:
        void closeEvent(QCloseEvent *event);
};

#endif