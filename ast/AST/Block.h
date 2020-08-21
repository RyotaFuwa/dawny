//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_BLOCK_H
#define DAWNY_BLOCK_H
#include <vector>
#include "Statement.h"


struct Block : Statement {
    Block();
    ~Block() override;
    std::vector<Statement*> statements;
};


#endif //DAWNY_BLOCK_H
