//
// Created by Ryota Fuwa on 2020/08/19.
//

#ifndef DAWNY_NODE_H
#define DAWNY_NODE_H
#include <string>


class Node {
public:
    virtual std::string GetLiteral() = 0;
    virtual std::string ToString() const = 0;
};


#endif //DAWNY_NODE_H
