#ifndef _AUTOMATON_HPP
#define _AUTOMATON_HPP

#include <QDebug>
#include <QTimer>

#include "history.hpp"
#include "stack.hpp"
#include "../io/file_worker.hpp"

class Automaton: public QObject
{
    Q_OBJECT
    
    public:
        static const QString DEFAULT_INPUT;
        
        Automaton(QObject *parent = nullptr);
        ~Automaton();
        
        // --- OVLADANI ANIMACE ---
        void play();
        void pause();
        void prevStep();
        void nextStep();
        void reset();
        void changeWaiting(double speed);
        void setInput(const QString &input);
        // ------------------------
        
        bool hasHistory();
        
        Grammar &getGrammar();
        Stack &getStack();
        const QStringList &getResultingRules();
        QString getDonePart();
        QString getProcessingPart();
        QString getWaitingPart();
        
    private:
        static const unsigned short BASE_MILLI_WAITING;
        
        bool end;
        QTimer *timer;
        unsigned short milliWaiting;
        
        Grammar grammar; // Gramatika.
        Stack stack; // Zasobnik.
        QList<History> changes; // Stavy (resp. zmeny) v historii.
        
        QStringList input; // Rozparsovany vstup.
        int inputIndex;
        QStringList resultingRules; // Vysledne indexy pravidel.
        
        void endProcessing(bool accept);
        void printState();
        
    private slots:
        void oneStep();
        
    signals:
        void hasNewHistory();
        void hasNotHistory();
        void hasNextStep();
        
        void clearSelection();
        void selectGrammarRow(int index);
        void selectParsingTableCell(int row, int column);
        
        void processResult(bool accept);
        void message(bool html, QString message);
        
        void inputChanged();
};

#endif