//
// Created by Ryota Fuwa on 2020/08/21.
//

#include "Infix.h"

Infix::Infix() {
}

Infix::~Infix() {
    delete left;
    delete right;
}
