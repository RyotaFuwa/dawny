//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PARSER_H
#define DAWNY_PARSER_H
#include "Program.h"
#include <Lexer.h>

namespace Parser {
    class Parser {
    public:
        Parser() : lexer(new Lexer::Lexer()) {};
        ~Parser() {delete lexer;};

        virtual Program Parse() = 0;
//        virtual Program Parse(std::vector<Token::Token>& tokens) = 0;

    protected:
        Lexer::Lexer *lexer;
    };
}


#endif //DAWNY_PARSER_H
