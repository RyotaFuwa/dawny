//
// Created by Ryota Fuwa on 2020/08/19.
//

#include "PrattParser.h"


Parser::PrattParser::PrattParser() {
}

Program Parser::PrattParser::Parse() {
    Program program;
    while(currentToken.type != Token::EOF_) {
        Statement statement = ParseStatement();
        if(!statement.empty) {
            program.statements.push_back(statement);
        }
        GetNextToken();
    }
}

Token::Token Parser::PrattParser::GetNextToken() {
    currentToken = nextToken;
    nextToken = lexer->GetNextToken();
}

Statement Parser::PrattParser::ParseStatement() {
    switch(currentToken.type) {
        case Token::LET:
            return ParseLet();
        default:
            break;
    }
    return Statement();
}

Statement Parser::PrattParser::ParseLet() {
    return Statement();
}



Expression Parser::PrattParser::ParsePrefix() {
    return Express
}

Expression Parser::PrattParser::ParseIdent() {
    return Expression();
}

Expression Parser::PrattParser::ParseInt() {
    return Expression();
}

Expression Parser::PrattParser::ParseBool() {
    return Expression();
}

Expression Parser::PrattParser::ParseGroup() {
    return Expression();
}

Expression Parser::PrattParser::ParseIfExpression() {
    return Expression();
}

Expression Parser::PrattParser::ParserFunction() {
    return Expression();
}

Expression Parser::PrattParser::ParseInfix() {
    return Expression();
}

Expression Parser::PrattParser::ParseCall() {
    return Expression();
}

