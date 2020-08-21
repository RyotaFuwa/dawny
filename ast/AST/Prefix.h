//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_PREFIX_H
#define DAWNY_PREFIX_H
#include "Expression.h"


struct Prefix : Expression {
    Prefix();
    ~Prefix() override;
    std::string op;
    Expression* right;
};


#endif //DAWNY_PREFIX_H
