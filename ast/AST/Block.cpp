//
// Created by Ryota Fuwa on 2020/08/21.
//

#include "Block.h"

Block::~Block() {
    for(auto statement: statements) {
        delete statement;
    }
}

Block::Block() {
}
