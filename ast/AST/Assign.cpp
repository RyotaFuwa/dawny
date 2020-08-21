//
// Created by Ryota Fuwa on 2020/08/21.
//

#include "Assign.h"


Assign::Assign() {
    type = NodeType::ASSIGN;
}

Assign::~Assign() {
    delete ident;
    delete expression;
}

std::string Assign::ToString() const {
    return ident->ToString() + " " + op + " " + expression->ToString();
}

