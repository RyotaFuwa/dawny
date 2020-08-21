//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_LET_H
#define DAWNY_LET_H
#include "Statement.h"
#include "Identifier.h"


struct Let : Statement {
    Let();
    ~Let() override;
    std::string ToString() const override;
    Identifier* ident;
    Expression* expression;
};


#endif //DAWNY_LET_H
