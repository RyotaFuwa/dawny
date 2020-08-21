//
// Created by Ryota Fuwa on 2020/08/20.
//

#ifndef DAWNY_RETURN_H
#define DAWNY_RETURN_H

#include "Statement.h"
#include "Expression.h"


struct Return : Statement {
    Return();
    ~Return() override;
    Expression* returnValue;
    std::string ToString() const override;
};


#endif //DAWNY_RETURN_H
