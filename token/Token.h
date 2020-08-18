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
using namespace std;

namespace Token {
    typedef string TokenType;

    const string ILLEGAL = "ILLEGAL";
    const string EOF_ = "EOF_";

// Identifiers + literals
    const string IDENT = "IDENT"; // add, foobar, x, y, ...
    const string INT = "INT";   // 1343456
    const string FLOAT = "FLOAT"; // 1.0, 1.343932

// Operators
    const string ASSIGN = "ASSIGN";
    const string PLUS = "PLUS";
    const string MINUS = "MINUS";
    const string BANG = "BANG";
    const string ASTERISK = "ASTERISK";
    const string SLASH = "SLASH";
    const string PERCENT = "PERCENT";

    const string IADD = "IADD";
    const string ISUB = "ISUB";
    const string IMUL = "IMUL";
    const string IDIV = "IDIV";
    const string IMOD = "IMOD";


    const string LT = "LT";
    const string LE = "LE";
    const string GT = "GT";
    const string GE = "GE";

    const string EQ = "EQ";
    const string NOT_EQ = "NOT_EQ";

// Delimiters
    const string COMMA = "COMMA";
    const string SEMICOLON = "SEMICOLON";
    const string COLON = "COLON";

    const string LPAREN = "LPAREN";
    const string RPAREN = "RPAREN";
    const string LBRACE = "LBRACE";
    const string RBRACE = "RBRACE";

// Keywords
    const string FUNCTION = "FUNCTION";
    const string LET = "LET";
    const string TRUE = "TRUE";
    const string FALSE = "FALSE";
    const string IF = "IF";
    const string ELSE = "ELSE";
    const string RETURN = "RETURN";

    struct Token {
        TokenType type;
        string literal;
    };
    static Token GetToken(TokenType tt, string literal) {
        Token token;
        token.type = tt;
        token.literal = literal;
        return token;
    }

    static std::ostream& operator<<(std::ostream& Ostream, const Token& token) {
        Ostream << "<" << token.type << ", " << token.literal << '>';
        return Ostream;
    };

    const map<string, TokenType> keywords{
            {"function",     FUNCTION},
            {"let",    LET},
            {"true",   TRUE},
            {"false",  FALSE},
            {"if",     IF},
            {"else",   ELSE},
            {"return", RETURN},
    };

    static TokenType LookUpIdent(string ident) {
        if (keywords.find(ident) == keywords.end()) {
            return IDENT;
        }
        return keywords.at(ident);
    }

    static TokenType LookUpNumberType(string number) {
        for(char c : number) {
            if(c == '.') return FLOAT;
        }
        return INT;
    }

}


#endif //DAWNY_TOKEN_H
