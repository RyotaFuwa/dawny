//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PARSER_H
#define DAWNY_PARSER_H
#include "Program.h"
#include <Lexer.h>

namespace Parser {
    enum SYNTAX {
        EQUAL,
        COMPARE,
        SUM,
        PRODUCT,
        PREFIX,
        CALL,
        FIELD,
    };

    map<Token::TokenType, SYNTAX> PREDECENCE{
            {Token::EQ,       SYNTAX::EQUAL},
            {Token::NOT_EQ,   SYNTAX::EQUAL},

            {Token::LT,       SYNTAX::COMPARE},
            {Token::LE,       SYNTAX::COMPARE},
            {Token::GT,       SYNTAX::COMPARE},
            {Token::GE,       SYNTAX::COMPARE},

            {Token::PLUS,     SYNTAX::SUM},
            {Token::MINUS,    SYNTAX::SUM},
            {Token::ASTERISK, SYNTAX::PRODUCT},
            {Token::SLASH,    SYNTAX::PRODUCT},
            {Token::PERCENT,  SYNTAX::PRODUCT},

            {Token::LPAREN,   SYNTAX::CALL}
    };

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
