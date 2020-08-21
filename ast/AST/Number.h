//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_NUMBER_H
#define DAWNY_NUMBER_H
#include "Expression.h"
#include "Token.h"


struct Number : Expression {
    std::string ToString() const override;
    Token::Token token; //might wanna destruct;
};


#endif //DAWNY_NUMBER_H
