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
#include <QScrollBar>

#include "tree.hpp"
#include "editor.hpp"
#include "input.hpp"
#include "report.hpp"
#include "table.hpp"
#include "text_area.hpp"
#include "../inner/automaton.hpp"
#include "../inner/parser.hpp"

/**
 * Instance teto tridy predstavuje hlavni okno.
 */ 
class MainWindow: public QMainWindow
{
    Q_OBJECT
    
    public:
        /**
         * Konstruktor nastavuje okno a vola funkci pro vytvoreni menu a layoutu.
         */         
        MainWindow();
        
        /**
         * Zavre okno pro upravu vstupniho textu a pro jistotu zavola uvolneni pameti
         * po hlavnim layoutu.
         */                          
        ~MainWindow();
        
    private:
        /**
         * Minimalni vyska okna.
         */                 
        static const int MIN_HEIGHT;
        
        /**
         * Minimalni sirka okna.
         */                 
        static const int MIN_WIDTH;
        
        /**
         * Objekt automatu.
         */                 
        Automaton automaton;
        
        /**
         * Rychlost animace.
         */                 
        double speed;
        
        /**
         * Okno pro zobrazeni derivacniho stromu.
         */                 
        Tree tree;
        
        /**
         * Okno pro upravu vstupniho textu.
         */                 
        Input *input;
        
        /**
         * Deklarace menu a tlacitek v menu.
         */                 
        QMenu *menu;
        QAction *scenariosAct;
        QAction *aboutAct;
        QAction *endAct;
        
        /**
         * Deklarace komponent pro vytvoreni hlavicky hlavniho okna.
         */                 
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
        
        /**
         * Deklarace komponent pro vytvoreni layoutu se vstupnim textem.
         */ 
        QPushButton inputSetter;
        QScrollArea *scrollProcessing;
        QLabel processing;
        QHBoxLayout processingLayout;
        
        /**
         * Deklarace komponent pro vytvoreni layoutu s vyberem gramatiky.
         */ 
        QLabel fileTitle;
        QLabel filePath;
        QPushButton chooseFile;
        QHBoxLayout fileChooserLayout;
        QVBoxLayout *fileLayout;
        
        /**
         * Deklarace komponent pro vytvoreni layoutu s tabulkou gramatiky.
         */ 
        QLabel gTitle;
        QPushButton gUpdate;
        QHBoxLayout gTitleLayout;
        Table gTable;
        QVBoxLayout *gLayout;
        
        /**
         * Deklarace komponent pro vytvoreni layoutu s tabulkou zasobniku.
         */ 
        QLabel sTitle;
        Table sTable;
        QVBoxLayout sLayout;
        
        /**
         * Vyber gramatiky, uprava gramatiky, tabulky s gramatikou a zasobnikem.
         */                 
        QVBoxLayout *leftBody;
        
        /**
         * Deklarace komponent pro vytvoreni layoutu s prechodovou tabulkou.
         */ 
        QLabel pTitle;
        Table pTable;
        QVBoxLayout pLayout;
        
        /**
         * Telo hlavniho okna = leftBody + pLayout.
         */                 
        QHBoxLayout *body;
        
        /**
         * Textova oblast pro vypis aktualniho stavu automatu.
         */                 
        TextArea messages;
        
        /**
         * Widget hlavniho layoutu.
         */                 
        QWidget *widget;
        
        /**
         * Hlavni layout.
         */                 
        QVBoxLayout *layout;
        
        /**
         * Funkce pro vytvoreni tacitek do menu.
         */                 
        void createActions();
        
        /**
         * Funkce pro vytvoreni menu.
         */                 
        void createMenu();
        
        /**
         * Funkce pro vytvoreni layoutu.
         */                 
        void createLayout();
        
        /**
         * Vrati vysledek zpracovani na tri oranzove pomlcky.
         */                 
        void resetResults();
        
        /**
         * Nastavi label s informaci o aktualni rychlosti.
         */                 
        void setSpeedLabel();
        
        /**
         * Nastavuje sirku labelu se vstupnim textem.
         * Musi byt zavolano az po inputChanged() - tam se nastavuje zobrazeny text (s HTML).
         */         
        void setProcessingWidth();
        
        /**
         * Jaka tlacitka maji byt zobrazena a jak skryta v pripade:
         * ze nebyla vybrana gramatika nebo ma text, predstavujici gramatiku, spatny format.
         */                 
        void buttonScenarioNoGrammar();
        
        /**
         * Jaka tlacitka maji byt zobrazena a jak skryta v pripade:
         * ze gramatika byla v poradku nactena.
         */                 
        void buttonScenarioOkGrammar();
        
        /**
         * Jaka tlacitka maji byt zobrazena a jak skryta v pripade:
         * ze je spustena animace zpracovani.
         */                 
        void buttonScenarioAnimation();
        
        /**
         * Meni vzhled prvniho tlacitka pro ovladani animace (prehravani, pauza).
         * @param bool play - true kdyz se ma nastavit sipka na prehravani.
         */
        void setPlayPauseView(bool play);
        
    private slots:
        /**
         * Upravuji viditelnost tlacitek pro krokovani.
         */                 
        void automatonHasHistory();
        void automatonHasNotHistory();
        void automatonHasNext();
        
        /**
         * Spousti nebo zastavuje animaci, meni pristupnost urcitych tlacitek.
         */                 
        void playPauseAnimation();
        
        /**
         * Vyvola navrat v historii, predchozi krok zpracovani.
         */                 
        void prevStep();
        
        /**
         * Posune vizualizaci o jeden krok zpracovani dal.
         */                 
        void nextStep();
        
        /**
         * Vrati stav zpracovani na zacatek.
         */                 
        void resetAnimation();
        
        /**
         * Zpomali animaci o jednu desetinu rychlosti.
         */                 
        void slowDown();
        
        /**
         * Zrychli animaci o jednu desetinu rychlosti.
         */                 
        void speedUp();
        
        /**
         * Zobrazi okno pro upravu vstupniho retezce.
         */                 
        void updateInput();
        
        /**
         * Provede restart animace, nastavi labelu novy vstupni retezec (novy retezec ulozi
         * i do automatu).
         */                 
        void setInput(const QString &input);
        
        /**
         * Otevre dialogove okno pro vyber gramatiky.
         */                 
        void chooseGrammar();
        
        /**
         * Otevre okno pro upravu gramatiky.
         */                 
        void editGrammar();
        
        /**
         * Funkce spolecna pro chooseGrammar() a editGrammar(). Jedna se o zpracovani
         * zmeneneho ci nacteneho textu gramatiky. Pripadne se zde vyplni tabulky.
         * Na zaver je uzivatel informovan o vysledku zpracovani.         
         */                 
        void setGrammar(const QString &grammar);
        
        /**
         * Zobrazi okno s akceptovatelnymi retezci pro dane gramatiky.
         */                 
        void showScenarios();
        
        /**
         * Zobrazi okno s informace o aplikaci.
         */                 
        void showAbout();
        
        /**
         * Vlozi dany text do textove oblasti ve spodni casti okna.
         * @param bool html - jestli obsahuje text pro vlozeni HTML atributy.
         * @param QString message - text, ktery ma byt vlozen.
         */                 
        void message(bool html, QString message);
        
        /**
         * Vypise v hlavicce a textove oblasti, jestli byl retezec akceptovan.
         * Dale meni pristupnost urcitych tlacitek.         
         * @param bool accept - jestli byl retezec akceptovan.         
         */                 
        void processResult(bool accept);
        
        /**
         * Upravuje vzhled zobrazeneho vstupniho retezce. Zmenit se muze vyber
         * slova, pripadne se muze posunout text tak, aby prave zpracovavane
         * slovo bylo priblizne uprostred obrazovky.         
         */                 
        void inputChanged();
        
    protected:
        /**
         * Funkce vyvolana pri zavirani okna.
         * @param QCloseEvent *event - vyvolana udalost.         
         */                 
        void closeEvent(QCloseEvent *event);
};

#endif