//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_PROGRAM_H
#define DAWNY_PROGRAM_H

#include <vector>
#include "Node.h"
#include "Statement.h"


class Program : public Node {
public:
    Program();
    std::string GetLiteral() override;
    std::string ToString() override;

private:
    std::vector<Statement> statements;
};


#endif //DAWNY_PROGRAM_H
