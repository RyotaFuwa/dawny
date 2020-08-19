//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_STATEMENT_H
#define DAWNY_STATEMENT_H
#include "Node.h"


struct Statement : Node {
    Statement();
    std::string ToString() const override;
    bool empty;
};


#endif //DAWNY_STATEMENT_H
