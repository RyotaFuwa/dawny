//
// Created by Ryota Fuwa on 2020/08/18.
//

//MEMO: float contains '.' in digits and in any cases where '.' is used other than float, '.' is
//not surrounded by numbers.

#ifndef DAWNY_TOKEN_H
#define DAWNY_TOKEN_H
#include <string>
#include <map>
#include <iostream>

namespace Token {
    enum TokenType {
        ILLEGAL,
        EOF_,

// Identifiers + literals
        IDENT,
        INT,
        FLOAT,

// Operators
        ASSIGN,
        PLUS,
        MINUS,
        BANG,
        ASTERISK,
        SLASH,
        PERCENT,

        IADD,
        ISUB,
        IMUL,
        IDIV,
        IMOD,

        LT,
        LE,
        GT,
        GE,

        EQ,
        NOT_EQ,

// Delimiters
        COMMA,
        SEMICOLON,
        COLON,

        LPAREN,
        RPAREN,
        LBRACE,
        RBRACE,

// Keywords
        FUNCTION,
        LET,
        TRUE,
        FALSE,
        IF,
        ELSE,
        RETURN,
    };

    const std::map<TokenType, std::string> TYPESTRING{
        {ILLEGAL, "ILLEGAL"},
        {EOF_, "EOF"},
        {IDENT, "IDENT"},
        {INT, "INT"},
        {FLOAT, "FLOAT"},
        {ASSIGN, "ASSIGN"},
        {PLUS, "PLUS"},
        {MINUS, "MINUS"},
        {BANG, "BANG"},
        {ASTERISK, "ASTERISK"},
        {SLASH, "SLASH"},
        {PERCENT, "PERCENT"},
        {IADD, "IADD"},
        {ISUB, "ISUB"},
        {IMUL, "IMUL"},
        {IDIV, "IDIV"},
        {IMOD, "IMOD"},
        {LT, "LT"},
        {LE, "LE"},
        {GT, "GT"},
        {GE, "GE"},
        {EQ, "EQ"},
        {NOT_EQ, "NOT_EQ"},
        {COMMA, "COMMA"},
        {SEMICOLON, "SEMICOLON"},
        {COLON, "COLON"},
        {LPAREN, "LPAREN"},
        {RPAREN, "RPAREN"},
        {LBRACE, "LBRACE"},
        {RBRACE, "RBRACE"},
        {FUNCTION, "FUNCTION"},
        {LET, "LET"},
        {TRUE, "TRUE"},
        {FALSE, "FALSE"},
        {IF, "IF"},
        {ELSE, "ELSE"},
        {RETURN, "RETURN"},
    };


    struct Token {
        TokenType type;
        std::string literal;
        std::string ToString() const {
            return "<" + TYPESTRING.at(type) + ", " + literal + '>';
        }
    };

    static Token GetToken(TokenType tt, std::string literal) {
        Token token;
        token.type = tt;
        token.literal = literal;
        return token;
    }

    static std::ostream& operator<<(std::ostream& Ostream, const Token& token) {
        Ostream << token.ToString();
        return Ostream;
    };

    const std::map<std::string, TokenType> keywords{
            {"function",     FUNCTION},
            {"let",    LET},
            {"true",   TRUE},
            {"false",  FALSE},
            {"if",     IF},
            {"else",   ELSE},
            {"return", RETURN},
    };

    static TokenType LookUpIdent(std::string ident) {
        if (keywords.find(ident) == keywords.end()) {
            return IDENT;
        }
        return keywords.at(ident);
    }

    static TokenType LookUpNumberType(std::string number) {
        for(char c : number) {
            if(c == '.') return FLOAT;
        }
        return INT;
    }

}


#endif //DAWNY_TOKEN_H
