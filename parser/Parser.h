//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PARSER_H
#define DAWNY_PARSER_H
#include "AST/Program.h"
#include <Lexer.h>
#include <AST/Let.h>
#include <AST/Return.h>
#include <AST/Assign.h>
#include <AST/ExpressionStatement.h>
#include <AST/Assign.h>
#include <AST/Block.h>

// top-down parser
namespace Parser {
    enum PRECEDENCE {
        EXPRESSION,
        EQUAL,
        COMPARE,
        SUM,
        PRODUCT,
        PREFIX,
        CALL,
        FIELD,
    };

    const std::map<Token::TokenType, PRECEDENCE> TOKEN_TO_PRECEDENCE{
            {Token::EQ,       PRECEDENCE::EQUAL},
            {Token::NOT_EQ,   PRECEDENCE::EQUAL},

            {Token::LT,       PRECEDENCE::COMPARE},
            {Token::LE,       PRECEDENCE::COMPARE},
            {Token::GT,       PRECEDENCE::COMPARE},
            {Token::GE,       PRECEDENCE::COMPARE},

            {Token::PLUS,     PRECEDENCE::SUM},
            {Token::MINUS,    PRECEDENCE::SUM},
            {Token::ASTERISK, PRECEDENCE::PRODUCT},
            {Token::SLASH,    PRECEDENCE::PRODUCT},
            {Token::PERCENT,  PRECEDENCE::PRODUCT},

            {Token::LPAREN,   PRECEDENCE::CALL}
    };

    class Parser {
    public:
        Parser();
        ~Parser();
        const Program* Parse(std::string = "");
//        virtual Program Parse(std::vector<Token::Token>& tokens) = 0;

    protected:
        void AdvanceToken();
        PRECEDENCE CurrentPrecedence();
        PRECEDENCE PeekPrecedence();
        bool ExpectNextTokenIs(Token::TokenType);

        //statement parse (pratt parser)
        Statement* ParseStatement();
        Let* ParseLet();
        Return* ParseReturn();
        Assign* ParseAssign();
        ExpressionStatement* ParseExpressionStatement();
        Block* ParseBlock();

        // prefix expression parser
        Expression* ParseExpression(PRECEDENCE);
        typedef Expression* (Parser::*PrefixFunction)(void);
        Expression* ParsePrefix();
        Expression* ParseIdent();
        Expression* ParseNumber();
        Expression* ParseBool();
        Expression* ParseGroup();

        Expression* ParseIf();
        Expression* ParseFunction();

        // infix expression parser
        typedef Expression* (Parser::*InfixFunction)(Expression*);
        //TODO: be careful with memory leak
        Expression* ParseInfix(Expression*);
        Expression* ParseCall(Expression*);

        // fields
        Lexer::Lexer *lexer;
        Program* program;

        Token::Token currentToken;
        Token::Token nextToken;
        std::vector<std::string> errors;
        std::map<Token::TokenType, PrefixFunction> prefixFunctionMap;
        std::map<Token::TokenType, InfixFunction> infixFunctionMap;
    };
}


#endif //DAWNY_PARSER_H
