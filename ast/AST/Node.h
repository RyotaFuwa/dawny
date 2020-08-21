//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_NODE_H
#define DAWNY_NODE_H
#include <string>

enum NodeType {
    NONE,
    //statement
    LET,
    ASSIGN,
    RETURN,
    IMPORT,

    //expression
    IF,
    FOR,
    WHILE,
    FUNCTION,
    CLASS,
};

struct Node {
    Node() {};
    virtual ~Node() {};
    // virtual std::string GetLiteral() = 0;
    virtual std::string ToString() const = 0;
    NodeType type;
};


#endif //DAWNY_NODE_H
