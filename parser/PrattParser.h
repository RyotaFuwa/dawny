//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PRATTPARSER_H
#define DAWNY_PRATTPARSER_H
#include <map>
#include "Parser.h"


namespace Parser {
    enum PRATT_RULE {
        EQUAL,
        COMPARE,
        SUM,
        PRODUCT,
        PREFIX,
        CALL,
        FIELD,
    };

    const map<Token::TokenType, PRATT_RULE> PRATT_TOKEN_TO_RULE{
            {Token::EQ, PRATT_RULE::EQUAL},
            {Token::NOT_EQ, PRATT_RULE::EQUAL},

            {Token::LT, PRATT_RULE::COMPARE},
            {Token::LE, PRATT_RULE::COMPARE},
            {Token::GT, PRATT_RULE::COMPARE},
            {Token::GE, PRATT_RULE::COMPARE},

            {Token::PLUS, PRATT_RULE::SUM},
            {Token::MINUS, PRATT_RULE::SUM},
            {Token::ASTERISK, PRATT_RULE::PRODUCT},
            {Token::SLASH, PRATT_RULE::PRODUCT},
            {Token::PERCENT, PRATT_RULE::PRODUCT},

            {Token::LPAREN, PRATT_RULE::CALL}
    };
    class PrattParser : public Parser {
    public:
        Program Parse() override;
    private:
    };
}

#endif //DAWNY_PRATTPARSER_H
