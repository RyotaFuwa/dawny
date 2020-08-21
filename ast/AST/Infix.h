//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_INFIX_H
#define DAWNY_INFIX_H
#include "Expression.h"

struct Infix : Expression {
    Infix();
    ~Infix() override;
    Expression *right;
    std::string op;
    Expression *left;
};


#endif //DAWNY_INFIX_H
