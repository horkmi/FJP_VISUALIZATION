#include "automaton.hpp"

const unsigned short Automaton::BASE_MILLI_WAITING = 2000;

Automaton::Automaton(const QString &input, QObject *parent): QObject(parent)
{
    end = false;
    milliWaiting = BASE_MILLI_WAITING;
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(oneStep()));
    
    setInput(input);
    inputIndex = -1;
}

Automaton::~Automaton()
{
    timer->stop();
    delete timer;
}

// -------------------------- OVLADANI ANIMACE ---------------------------------

void Automaton::play()
{
    timer->start(milliWaiting);
}

void Automaton::pause()
{
    timer->stop();
}

void Automaton::prevStep()
{
    if (changes.size() > 0)
    {
        end = false;
        emit hasNextStep();
        emit message(false, trUtf8("Návrat o jeden krok zpět."));
        
        History last = changes.takeLast();
        if (!hasHistory())
        {
            emit hasNotHistory();
        }
        
        if (last.isSelectedCell())
        {
            // Byl zmen vyber v tabulkach.
            int found = -1;
            for (int i = changes.size() - 1; i >= 0; i--)
            {
                // Najit posledni zmenu vyberu.
                if (changes[i].isSelectedCell())
                {
                    found = i;
                    break;
                }
            }
            
            if (found >= 0)
            {
                emit selectGrammarRow(changes.at(found).stackAdded);
                emit selectParsingTableCell(changes.at(found).selectedCell.x(), changes.at(found).selectedCell.y());
            }
            else
            {
                emit clearSelection();
            }
        }
        if (last.isStackAdded())
        {
            // Byla provedena expanze.
            if (last.isStart())
            {
                stack.pop();
            }
            else
            {
                stack.pop(grammar.getRule(last.stackAdded).getRule().size());
                resultingRules.removeLast();
            }
        }
        if (last.isStackRemoved())
        {
            // Ze zasobniku byl odebran terminal/neterminal.
            stack.push(last.getStackRemoved());
        }
        if (last.isInputIndexChanged())
        {
            // Byl zvysen index odkazujici na rozebiranou cast ve vstupnim retezci.
            inputIndex--;
            emit inputChanged();
        }
        printState();
    }
    else
    {
        emit message(false, trUtf8("Návrat není možný, nacházíte se na začátku."));
    }
}

void Automaton::nextStep()
{
    oneStep();
}

void Automaton::reset()
{
    end = false;
    timer->stop();
    inputIndex = -1;
    changes.clear();
    resultingRules.clear();
    stack.clear();
    emit inputChanged();
    emit clearSelection();
}

void Automaton::changeWaiting(double speed)
{
    // Pri rychlosti pod jedna zpomalovat, nad jedna zrychlovat.
    milliWaiting = static_cast<unsigned short>(BASE_MILLI_WAITING * (1.0 / speed));
    timer->setInterval(milliWaiting);
}

void Automaton::setInput(const QString &input)
{
    this->input = input.split(" ", QString::SkipEmptyParts);
}

// ----------------------------------------------------------------------------

bool Automaton::hasHistory()
{
    return changes.size() > 0;
}

Grammar &Automaton::getGrammar()
{
    return grammar;
}

Stack &Automaton::getStack()
{
    return stack;
}

const QStringList &Automaton::getResultingRules()
{
    return resultingRules;
}

QString Automaton::getDonePart()
{
    return inputIndex >= 0 ? input.mid(0, inputIndex).join(" ") : "";
}

QString Automaton::getProcessingPart()
{
    // Na zacatku je inputIndex = -1!
    return (inputIndex < input.size() && inputIndex >= 0) ? input.at(inputIndex) : "";
}

QString Automaton::getWaitingPart()
{
    return input.mid(inputIndex + 1).join(" ");
}

void Automaton::oneStep()
{
    History record;
    if (inputIndex < 0)
    {
        inputIndex = 0;
        record.inputIndexChanged = true;
        stack.push(1);
        record.stackAdded = 1;
        record.start = true;
        emit inputChanged();
    }
    else if (stack.isEmpty())
    {
        // Pokud je zasobnik prazdny = KONEC a zalezi, jestli je jeste neco na vstupu.
        endProcessing(inputIndex >= input.size());
    }
    else
    {
        int sTopIndex = stack.pop();
        record.setStackRemoved(sTopIndex);
        
        // V pripade, kdy je na vrcholu prazdny symbol, rovnou pokracovat.
        if (sTopIndex != 0)
        {
            // Zjistit index dalsiho terminalu na vstupu (EPS. v pripade, ze na vstupu uz nic noveho neni).
            int iFirstIndex = grammar.getTerminalsSize() + 1; // EPS. sloupec v tabulce.
            if (inputIndex < input.size())
            {
                iFirstIndex = grammar.getWordIndex(true, input.at(inputIndex)); // Index nejakeho terminalu.
            }
            
            // Vyhodnotit.                                                                               // Na prvnich pozicich nic neni, potrebujeme skutecne indexy (nyni uz muzeme zmensit natrvalo).
            if (iFirstIndex < 0 || (sTopIndex < 0 && sTopIndex * -1 != iFirstIndex) || (sTopIndex > 0 && grammar.getRuleIndex(--sTopIndex, --iFirstIndex) < 0))
            {
                // A) uzivatelem zadany terminal neni v seznamu.
                // B) na vrcholu zasobniku byl terminal, ale neshoduje se se vstupem.
                // C) na vrcholu zasobniku byl neterminal, ale neexistuje pozadovane pravidlo.
                endProcessing(false);
            }
            else if (sTopIndex < 0)
            {
                // Na vrcholu zasobniku terminal shodujici se se vstupem => srovnani.
                inputIndex++;
                record.inputIndexChanged = true;
                emit inputChanged();
            }
            else
            {
                // Na vrcholu zasobniku neterminal, spolu s terminalem na vstupu existuje pravidlo => expanze.
                int ruleIndex = grammar.getRuleIndex(sTopIndex, iFirstIndex);
                stack.append(grammar.getRule(ruleIndex));
                resultingRules.append(QString::number(ruleIndex + 1));
                
                record.selectedCell = QPoint(sTopIndex, iFirstIndex);
                record.stackAdded = ruleIndex;
                
                emit selectGrammarRow(ruleIndex);
                emit selectParsingTableCell(sTopIndex, iFirstIndex);
            }
        }
    }
    changes.append(record);
    
    if (!timer->isActive())
    {
        emit hasNewHistory();
    }
    
    if (!end)
    {
        // Pokud jeste nenastal konec, vypsat stav po jednom kroce.
        printState();
    }
}

void Automaton::endProcessing(bool accept)
{
    emit clearSelection();
    emit processResult(accept);
    end = true;
    timer->stop();
}

void Automaton::printState()
{
    emit message(false, QString("(%1 | %2 | %3)").arg(input.mid(inputIndex).join(" ").toUtf8().data(), stack.toString(grammar).toUtf8().data(), resultingRules.join(", ").toUtf8().data()));
}