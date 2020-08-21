//
// Created by Ryota Fuwa on 2020/08/21.
//

#ifndef DAWNY_EXPRESSIONSTATEMENT_H
#define DAWNY_EXPRESSIONSTATEMENT_H
#include "Statement.h"
#include "Expression.h"


struct ExpressionStatement : Statement {
    ExpressionStatement();
    ~ExpressionStatement();
    Expression* expression;
};


#endif //DAWNY_EXPRESSIONSTATEMENT_H
