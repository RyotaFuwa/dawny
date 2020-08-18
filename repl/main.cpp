//
// Created by Ryota Fuwa on 2020/08/19.
//

#include <iostream>
#include <Lexer.h>

const string PROMPT = "Dawny >>";

int main() {
    while(true) {
        string line;
        std::cout << PROMPT;
        std::getline(std::cin, line);
        if(line == "exit") break;

        Lexer::Lexer lexer(line);

        for(auto token : lexer.Parse()) {
            std::cout << token;
        }
        std::cout << std::endl;
    }
    return 0;
}
