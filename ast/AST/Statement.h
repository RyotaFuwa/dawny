//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_STATEMENT_H
#define DAWNY_STATEMENT_H
#include <map>
#include "Node.h"


struct Statement : Node {
    Statement() {};
    virtual ~Statement() {};
    virtual std::string ToString() const override;
};


#endif //DAWNY_STATEMENT_H
