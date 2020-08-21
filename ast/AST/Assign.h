//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_ASSIGN_H
#define DAWNY_ASSIGN_H
#include "Statement.h"
#include "Identifier.h"
#include "Token.h"

// basically same as Let, but created to difference those two.
struct Assign : Statement  {
    Assign();
    ~Assign() override;
    std::string ToString() const override;
    Identifier* ident;
    std::string op;
    Expression* expression;
};


#endif //DAWNY_ASSIGN_H
