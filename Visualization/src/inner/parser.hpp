#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <QString>
#include <QRegExp>
#include <QDebug>

#include "../inner/grammar.hpp"

class Parser
{
    public:
        static bool parseGrammar(Grammar &grammar, const QString &text);
};

#endif