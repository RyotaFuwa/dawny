//
// Created by Ryota Fuwa on 2020/08/19.
//

#include "Let.h"

Let::Let() {
    type = NodeType::LET;
}

Let::~Let() {
    delete ident;
    delete expression;
}

std::string Let::ToString() const {
    return "let " + ident->ToString() + " = " + expression->ToString();
}
