//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_EXPRESSION_H
#define DAWNY_EXPRESSION_H

#include "Node.h"


struct Expression : Node {
    Expression();
    virtual ~Expression();
    virtual std::string ToString() const override;
};


#endif //DAWNY_EXPRESSION_H
