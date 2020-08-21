//
// Created by Ryota Fuwa on 2020/08/20.
//

#include "Return.h"


Return::Return() {
    type = NodeType::RETURN;
}

Return::~Return() {
    delete returnValue;
}

std::string Return::ToString() const {
    return "return " + returnValue->ToString();
}

