//
// Created by Ryota Fuwa on 2020/08/18.
//

#ifndef DAWNY_LEXER_H
#define DAWNY_LEXER_H
#include <string>
#include <iostream>
#include <vector>
#include "Token.h"

namespace Lexer {

    class Lexer {
    public:
        Lexer();
        explicit Lexer(std::string);
        ~Lexer();
        friend std::ostream& operator<<(std::ostream&, Lexer&);

        Token::Token GetNewToken();
        std::vector<Token::Token> Parse();

        static bool isLetter(char);
        static bool isNumber(char);

    protected:
        void Reset();
        void SkipWhitespace();
        void ReadChar();
        char PeekChar();
        std::string readIdentifier();
        std::string readNumber();

        std::string codeText;
        char c;
        int position;
        int nextPosition;
    };
}


#endif //DAWNY_LEXER_H
