//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PRATTPARSER_H
#define DAWNY_PRATTPARSER_H
#include <map>
#include "Parser.h"
#include "Expression.h"

namespace Parser {

    class PrattParser : public Parser {
    public:
        PrattParser();
        Program Parse() override;
    private:
        Token::Token GetNextToken();

        //statement parse
        Statement ParseStatement();
        Statement ParseLet();

        // prefix
        typedef Expression PrefixFunction(void);
        Expression ParsePrefix();
        Expression ParseIdent();
        Expression ParseInt();
        Expression ParseBool();
        Expression ParseGroup();
        Expression ParseIfExpression();
        Expression ParserFunction();

        // infix
        typedef Expression (*InfixFunction)(Expression&);
        Expression ParseInfix();
        Expression ParseCall();

        std::vector<std::string> errors;

        Token::Token currentToken;
        Token::Token nextToken;

        std::map<Token::TokenType, PrefixFunction> prefixFunctionMap;
        std::map<Token::TokenType, InfixFunction> infixFunctionMap;
    };
}

#endif //DAWNY_PRATTPARSER_H
