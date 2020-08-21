//
// Created by Ryota Fuwa on 2020/08/19.
//

#include <AST/Block.h>
#include <AST/Number.h>
#include <AST/Prefix.h>
#include <AST/Infix.h>
#include <AST/Bool.h>
#include "Parser.h"


Parser::Parser::Parser() : lexer(new Lexer::Lexer()), program(nullptr) {
    prefixFunctionMap.insert(std::make_pair(Token::IDENT, &Parser::ParseIdent));
    prefixFunctionMap.insert(std::make_pair(Token::INT, &Parser::ParseNumber));
    prefixFunctionMap.insert(std::make_pair(Token::FLOAT, &Parser::ParseNumber));
    prefixFunctionMap.insert(std::make_pair(Token::BANG, &Parser::ParsePrefix));
    prefixFunctionMap.insert(std::make_pair(Token::MINUS, &Parser::ParseIdent));
    prefixFunctionMap.insert(std::make_pair(Token::TRUE, &Parser::ParseBool));
    prefixFunctionMap.insert(std::make_pair(Token::FALSE, &Parser::ParseBool));
    prefixFunctionMap.insert(std::make_pair(Token::LPAREN, &Parser::ParseGroup));
    prefixFunctionMap.insert(std::make_pair(Token::IF, &Parser::ParseIf));
    prefixFunctionMap.insert(std::make_pair(Token::FUNCTION, &Parser::ParseFunction));

    infixFunctionMap.insert(std::make_pair(Token::PLUS, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::MINUS, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::ASTERISK, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::SLASH, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::EQ, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::NOT_EQ, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::LT, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::LE, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::GT, &Parser::ParseInfix));
    infixFunctionMap.insert(std::make_pair(Token::GE, &Parser::ParseInfix));

    infixFunctionMap.insert(std::make_pair(Token::LPAREN, &Parser::ParseCall));
};

Parser::Parser::~Parser() {delete lexer; delete program;};

const Program* Parser::Parser::Parse(std::string input) {
    // initialize lexer and have currentToken and nextToken all set.
    lexer->Reset(input);
    AdvanceToken();
    AdvanceToken();

    delete program;
    program = new Program();

    //parsing
    while(currentToken.type != Token::EOF_) {
        Statement* statement = ParseStatement();
        if(statement != nullptr) {
            program->statements.push_back(statement);
        }
        AdvanceToken();
    }
    return program;
}

void Parser::Parser::AdvanceToken() {
    currentToken = nextToken;
    nextToken = lexer->GetNextToken();
}

Parser::PRECEDENCE Parser::Parser::CurrentPrecedence() {
    Token::TokenType type = currentToken.type;
    auto pair = TOKEN_TO_PRECEDENCE.find(type);
    if(pair == TOKEN_TO_PRECEDENCE.end()) return EXPRESSION;
    return pair->second;
}

Parser::PRECEDENCE Parser::Parser::PeekPrecedence() {
    Token::TokenType type = nextToken.type;
    auto pair = TOKEN_TO_PRECEDENCE.find(type);
    if(pair == TOKEN_TO_PRECEDENCE.end()) return EXPRESSION;
    return pair->second;
}

bool Parser::Parser::ExpectNextTokenIs(Token::TokenType tt) {
    if(nextToken.type == tt) {
        AdvanceToken();
        return true;
    }
    return false;
}

Statement* Parser::Parser::ParseStatement() {
    switch(currentToken.type) {
        case Token::LET:
            return ParseLet();
        case Token::RETURN:
            return ParseReturn();
        case Token::IDENT: {
            bool notValidToken = !(
                    nextToken.type == Token::IADD ||
                    nextToken.type == Token::ISUB ||
                    nextToken.type == Token::IMUL ||
                    nextToken.type == Token::IDIV ||
                    nextToken.type == Token::IMOD ||
                    nextToken.type == Token::ASSIGN
            );
            if (notValidToken) {
                return ParseExpressionStatement();
            } else {
                return ParseAssign();
            }
        }
        default:
            return ParseExpressionStatement();
    }
}

Let* Parser::Parser::ParseLet() {
    if(!ExpectNextTokenIs(Token::IDENT))  return nullptr;
    std::string name = currentToken.literal;
    if(!ExpectNextTokenIs(Token::ASSIGN)) return nullptr;
    AdvanceToken();
    Expression* expression = ParseExpression(EXPRESSION);
    if(expression == nullptr) return nullptr;

    if(currentToken.type == Token::SEMICOLON) AdvanceToken();

    Let* stml = new Let();
    stml->ident = new Identifier(name);
    stml->expression = expression;
    return stml;
}

Return* Parser::Parser::ParseReturn() {
    AdvanceToken();
    Expression* expression = ParseExpression(EXPRESSION);
    if(expression == nullptr) return nullptr;

    Return* stml = new Return();
    stml->returnValue = expression;
    return stml;
}

Assign* Parser::Parser::ParseAssign() {
    std::string name = currentToken.literal;
    AdvanceToken();
    std::string op = currentToken.literal;
    AdvanceToken();
    Expression* expression = ParseExpression(EXPRESSION);
    if(expression == nullptr) return nullptr;
    if(currentToken.type == Token::SEMICOLON) AdvanceToken();

    Assign *stml = new Assign();
    stml->ident = new Identifier(name);
    stml->op = op;
    stml->expression = expression;
    return stml;
}

ExpressionStatement *Parser::Parser::ParseExpressionStatement() {
    Expression *expression = ParseExpression(EXPRESSION);
    if(expression == nullptr) return nullptr;
    if(currentToken.type == Token::SEMICOLON) AdvanceToken();
    ExpressionStatement *stml = new ExpressionStatement();
    stml->expression = expression;
    return stml;
}

Block *Parser::Parser::ParseBlock() {
    AdvanceToken();
    Block *block = new Block();
    while(currentToken.type != Token::RBRACE) {
        Statement* stml = ParseStatement();
        if(stml != nullptr) {
            block->statements.push_back(stml);
        }
        AdvanceToken();
    }
    return block;
}

Expression* Parser::Parser::ParseExpression(PRECEDENCE p) {
    auto prefix_pair = prefixFunctionMap.find(currentToken.type);
    if(prefix_pair == prefixFunctionMap.end()) {
        //Error
        return nullptr;
    }
    PrefixFunction prefix = prefix_pair->second;
    Expression* leftExpression = (this->*prefix)();

    while(nextToken.type != Token::SEMICOLON && (p < PeekPrecedence())) {
        auto infix_pair = infixFunctionMap.find(nextToken.type);
        if(infix_pair == infixFunctionMap.end()) {
            return leftExpression;
        }

        AdvanceToken(); //the type of next token already checked

        InfixFunction infix = infix_pair->second;
        leftExpression = (this->*infix)(leftExpression);
    }
    return leftExpression;
}

Expression* Parser::Parser::ParsePrefix() {
    Prefix *prefix = new Prefix();
    prefix->op = currentToken.literal;
    AdvanceToken();
    prefix->right = ParseExpression(PREFIX);
    return prefix;
}

Expression* Parser::Parser::ParseIdent() {
    return new Identifier(currentToken.literal);
}

Expression* Parser::Parser::ParseNumber() {
    Number* num = new Number();
    num->token = currentToken;
    return num;
}

Expression* Parser::Parser::ParseBool() {
    Bool *bool_ = new Bool();
    bool_->token = currentToken;
    return bool_;
}

Expression* Parser::Parser::ParseGroup() {
    AdvanceToken();
    Expression *expression = ParseExpression(EXPRESSION);
    if(!ExpectNextTokenIs(Token::RPAREN)) {
        delete expression;
        return nullptr;
    }
    return expression;
}

Expression* Parser::Parser::ParseIf() {
    //at if now
    AdvanceToken();

    Expression* condition = ParseExpression(EXPRESSION);
    if(condition == nullptr) return nullptr;

    if(!ExpectNextTokenIs(Token::LBRACE)) {
        delete condition;
        return nullptr;
    }

    Block* ifSo = ParseBlock();
    Block* ifNot = nullptr;
    if(nextToken.type == Token::ELSE) {
        AdvanceToken();
        if(ExpectNextTokenIs(Token::LBRACE)) {
            delete condition;
            delete ifSo;
        }
        ifNot = ParseBlock();
    }
    //If node
    // add those nodes
    // return it
    return nullptr;
}

Expression* Parser::Parser::ParseInfix(Expression* left) {
    Infix *infix = new Infix();
    infix->left = left;
    infix->op = currentToken.literal;
    PRECEDENCE precedence = CurrentPrecedence();
    AdvanceToken();
    infix->right = ParseExpression(precedence);
    return infix;
}

Expression* Parser::Parser::ParseFunction() {
    return nullptr;
}

Expression* Parser::Parser::ParseCall(Expression*) {
    return nullptr;
}



