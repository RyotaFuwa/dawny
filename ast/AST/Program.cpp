//
// Created by Ryota Fuwa on 2020/08/19.
//

#include "Program.h"

Program::Program() {
}

Program::~Program() {
    for(auto statement: statements) {
        delete statement;
    }
}

/*
std::string Program::GetLiteral() {
    return std::string();
}
*/

std::string Program::ToString() const {
    std::string out = "";
    for(const Statement* statement : statements) {
        out += statement->ToString() + "\n";
    }
    return out;
}

