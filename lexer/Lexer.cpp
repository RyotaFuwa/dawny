//
// Created by Ryota Fuwa on 2020/08/18.
//

#include <string>
#include <iostream>
#include "Lexer.h"
using namespace std;


Lexer::Lexer::Lexer() : codeText(""), position(0), nextPosition(1), c(0) {
}

Lexer::Lexer::Lexer(string input) : codeText(input), position(0), nextPosition(1) {
    if(!codeText.empty())
        c = codeText[position];
    else
        c = 0;
}

Lexer::Lexer::~Lexer() {
}

Token::Token Lexer::Lexer::GetNewToken() {
    Token::Token token;

    SkipWhitespace();

    switch(this->c) {
        case '=':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::EQ, literal);
            }
            else {
                token = Token::GetToken(Token::ASSIGN, string() + this->c);
            }
            break;
        case '+':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::IADD, literal);
            }
            else {
                token = Token::GetToken(Token::PLUS, string() + this->c);
            }
            break;
        case '-':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::ISUB, literal);
            }
            else {
                token = Token::GetToken(Token::MINUS, string() + this->c);
            }
            break;
        case '*':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::IMUL, literal);
            }
            else {
                token = Token::GetToken(Token::ASTERISK, string() + this->c);
            }
            break;
        case '/':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token.type = Token::IDIV;
                token.literal = literal;
            }
            else {
                token.type = Token::SLASH;
                token.literal = string() + this->c;
            }
            break;
        case '%':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::IMOD, literal);
            }
            else {
                token = Token::GetToken(Token::PERCENT, string() + this->c);
            }
            break;
        case '!':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::NOT_EQ, literal);
            }
            else {
                token = Token::GetToken(Token::BANG, string() + this->c);
            }
            break;
        case '<':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::LE, literal);
            }
            else {
                token = Token::GetToken(Token::LT, string() + this->c);
            }
            break;
        case '>':
            if(PeekChar() == '=') {
                char c = this->c;
                ReadChar();
                string literal = string() + c + this->c;
                token = Token::GetToken(Token::GE, literal);
            }
            else {
                token = Token::GetToken(Token::GT, string() + this->c);
            }
            break;
        case ';':
            token = Token::GetToken(Token::SEMICOLON, string() + this->c);
            break;
        case ':':
            token = Token::GetToken(Token::COLON, string() + this->c);
            break;
        case ',':
            token = Token::GetToken(Token::COMMA, string() + this->c);
            break;
        case '{':
            token = Token::GetToken(Token::LBRACE, string() + this->c);
            break;
        case '}':
            token = Token::GetToken(Token::RBRACE, string() + this->c);
            break;
        case '(':
            token = Token::GetToken(Token::LPAREN, string() + this->c);
            break;
        case ')':
            token = Token::GetToken(Token::RPAREN, string() + this->c);
            break;
        case 0:
            token = Token::GetToken(Token::EOF_, "");
            break;
        default:
            if(isLetter(this->c)) {
                token.literal = readIdentifier();
                token.type = Token::LookUpIdent(token.literal);
            }
            else if(isNumber(this->c)) {
                token.literal = readNumber();
                token.type = Token::LookUpNumberType(token.literal);
            }
            else {
                token = Token::GetToken(Token::ILLEGAL, string() + this->c);
            }
            return token;
    }
    ReadChar();
    return token;
}

bool Lexer::Lexer::isLetter(char c) {
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || c == '_';
}

bool Lexer::Lexer::isNumber(char c) {
    // DOT '.' is also part of number in digit.
    return '0' <= c && c <= '9' || c == '.';
}

void Lexer::Lexer::SkipWhitespace() {
    while(this->c == ' ' || this->c == '\t' || this->c == '\n' || this->c == '\r') {
        ReadChar();
    }
}

void Lexer::Lexer::ReadChar() {
    if(nextPosition >= codeText.size()) {
        c = 0;
    }
    else {
        c = codeText[nextPosition];
    }
    position = nextPosition;
    nextPosition += 1;
}

char Lexer::Lexer::PeekChar() {
    if(nextPosition >= codeText.size()) {
        return 0;
    }
    return codeText[nextPosition];
}

string Lexer::Lexer::readIdentifier() {
    int pos = position;
    while(isLetter(c)) {
        ReadChar();
    }
    return codeText.substr(pos, position - pos);
}

string Lexer::Lexer::readNumber() {
    int pos = position;
    while(isNumber(c)) {
        ReadChar();
    }
    return codeText.substr(pos, position - pos);
}

std::ostream& Lexer::operator<<(std::ostream& Ostream, Lexer& lexer) {
    std::vector<Token::Token> tokens = lexer.Parse();
    for(auto i = tokens.begin(); i != tokens.end(); i++) {
        Ostream << *i << ", ";
    }
    return Ostream;
}

std::vector<Token::Token> Lexer::Lexer::Parse() {
    std::vector<Token::Token> tokens;
    Reset();
    while(true) {
        Token::Token token = GetNewToken();
        tokens.push_back(token);
        if(token.type == Token::EOF_ || token.type == Token::ILLEGAL)
            break;
    }
    return tokens;
}

void Lexer::Lexer::Reset() {
    position = 0;
    nextPosition = 1;
    if(!codeText.empty())
        c = codeText[0];
    else
        c = 0;
}


