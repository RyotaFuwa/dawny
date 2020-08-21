//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PROGRAM_H
#define DAWNY_PROGRAM_H

#include <vector>
#include "Node.h"
#include "Statement.h"


struct Program : Node {
public:
    Program();
    ~Program() override;
//    std::string GetLiteral() override;
    std::string ToString() const override;
    std::vector<const Statement*> statements;
};


#endif //DAWNY_PROGRAM_H
