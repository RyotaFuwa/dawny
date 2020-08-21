//
// Created by Ryota Fuwa on 2020/08/20.
//

#include "Identifier.h"

Identifier::Identifier(const std::string& v) : value{v} {
}

std::string Identifier::ToString() const {
    return value;
}
