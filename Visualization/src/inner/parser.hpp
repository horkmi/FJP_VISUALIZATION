#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <QString>
#include <QRegExp>
#include <QDebug>

#include "../inner/grammar.hpp"

/**
 * Obsahuje pouze jednu funkci, statickou, pro rozparsovani hrubeho textu do bezkontextove gramatiky.
 */ 
class Parser
{
    public:
        /**
         * Rozdeli vstupni text a postupne uklada do gramatiky terminaly, neterminaly a prepisovaci pravidla.
         * @param Grammar &grammar - odkaz na gramatiku.
         * @param const QString &text - hruby text, ve kterem by mely byt udaje bezkontextove gramatiky.
         * @return jestli byla gramatika v poradku nactena.                           
         */                 
        static bool parseGrammar(Grammar &grammar, const QString &text);
};

#endif