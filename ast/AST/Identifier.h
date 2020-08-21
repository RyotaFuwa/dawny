//
// Created by Ryota Fuwa on 2020/08/20.
//

#ifndef DAWNY_IDENTIFIER_H
#define DAWNY_IDENTIFIER_H
#include <string>
#include "Expression.h"


struct Identifier : Expression {
    Identifier(const std::string&);
    std::string ToString() const override;
    std::string value; //name of identifier
};


#endif //DAWNY_IDENTIFIER_H
