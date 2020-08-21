//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_BOOL_H
#define DAWNY_BOOL_H

#include <Token.h>
#include "Expression.h"

struct Bool : Expression {
    std::string ToString() const override;
    Token::Token token;
};


#endif //DAWNY_BOOL_H
