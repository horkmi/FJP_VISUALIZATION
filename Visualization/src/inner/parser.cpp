#include "parser.hpp"

bool Parser::parseGrammar(Grammar &grammar, const QString &text)
{
    bool results = true;
    
    // Vymazat predchozi gramatiku.
    grammar.clear();
    
    QString nonterminal;
    QList<QString> rule;
    int state = 0; // 0 = neterminal, 1 = :, 2 = pravidla.
    
    QStringList splitted = text.split(QRegExp("\\s+"), QString::SkipEmptyParts); // \s je jakykoli byly znak, aneb [\r\n\t ...].
    for (int i = 0; i < splitted.size(); i++)
    {
        if (state == 0)
        {
            nonterminal.append(splitted.at(i));
            state++;
        }
        else if (state == 1)
        {
            if (splitted.at(i).compare(":") == 0)
            {
                state++;
            }
            else
            {
                grammar.clear();
                results = false; // Text ma spatny format.
                break;
            }
        }
        else
        {
            if (splitted.at(i).compare("|") == 0)
            {
                grammar.append(nonterminal, rule);
                rule.clear();
            }
            else if (splitted.at(i).compare(";") == 0)
            {
                grammar.append(nonterminal, rule);
                nonterminal.clear();
                rule.clear();
                state = 0;
            }
            else
            {
                rule.append(splitted.at(i));
            }
        }
    }
    
    return results;
}