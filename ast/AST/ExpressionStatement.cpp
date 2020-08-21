//
// Created by Ryota Fuwa on 2020/08/21.
//

#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement() {
    expression = nullptr;
}

ExpressionStatement::~ExpressionStatement() {
    delete expression;
}
