//
// Created by Ryota Fuwa on 2020/08/18.
//
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include <Lexer.h>

TEST(LexerTest, ReturnCorrectTokens
) {
    std::string input = R"(
    let five = 5.3;
    let ten = 10;

    let add = function(x, y) {
      x + y;
    };

    let result = add(five, ten);
    !-/*5;
    5 < 10 > 5;

    if (5 < 10) {
        return true;
    } else {
        return false;
    }

    10 == 10;
    10 != 9;
    )";
    Lexer::Lexer lexer(input);

    std::vector<Token::Token> tokens{
            Token::GetToken(Token::LET, "let"),
            Token::GetToken(Token::IDENT, "five"),
            Token::GetToken(Token::ASSIGN, "="),
            Token::GetToken(Token::FLOAT, "5.3"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::LET, "let"),
            Token::GetToken(Token::IDENT, "ten"),
            Token::GetToken(Token::ASSIGN, "="),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::LET, "let"),
            Token::GetToken(Token::IDENT, "add"),
            Token::GetToken(Token::ASSIGN, "="),
            Token::GetToken(Token::FUNCTION, "function"),
            Token::GetToken(Token::LPAREN, "("),
            Token::GetToken(Token::IDENT, "x"),
            Token::GetToken(Token::COMMA, ","),
            Token::GetToken(Token::IDENT, "y"),
            Token::GetToken(Token::RPAREN, ")"),
            Token::GetToken(Token::LBRACE, "{"),
            Token::GetToken(Token::IDENT, "x"),
            Token::GetToken(Token::PLUS, "+"),
            Token::GetToken(Token::IDENT, "y"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::RBRACE, "}"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::LET, "let"),
            Token::GetToken(Token::IDENT, "result"),
            Token::GetToken(Token::ASSIGN, "="),
            Token::GetToken(Token::IDENT, "add"),
            Token::GetToken(Token::LPAREN, "("),
            Token::GetToken(Token::IDENT, "five"),
            Token::GetToken(Token::COMMA, ","),
            Token::GetToken(Token::IDENT, "ten"),
            Token::GetToken(Token::RPAREN, ")"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::BANG, "!"),
            Token::GetToken(Token::MINUS, "-"),
            Token::GetToken(Token::SLASH, "/"),
            Token::GetToken(Token::ASTERISK, "*"),
            Token::GetToken(Token::INT, "5"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::INT, "5"),
            Token::GetToken(Token::LT, "<"),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::GT, ">"),
            Token::GetToken(Token::INT, "5"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::IF, "if"),
            Token::GetToken(Token::LPAREN, "("),
            Token::GetToken(Token::INT, "5"),
            Token::GetToken(Token::LT, "<"),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::RPAREN, ")"),
            Token::GetToken(Token::LBRACE, "{"),
            Token::GetToken(Token::RETURN, "return"),
            Token::GetToken(Token::TRUE, "true"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::RBRACE, "}"),
            Token::GetToken(Token::ELSE, "else"),
            Token::GetToken(Token::LBRACE, "{"),
            Token::GetToken(Token::RETURN, "return"),
            Token::GetToken(Token::FALSE, "false"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::RBRACE, "}"),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::EQ, "=="),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::INT, "10"),
            Token::GetToken(Token::NOT_EQ, "!="),
            Token::GetToken(Token::INT, "9"),
            Token::GetToken(Token::SEMICOLON, ";"),
            Token::GetToken(Token::EOF_, ""),
    };
    for(auto correctToken : tokens) {
        Token::Token token = lexer.GetNewToken();
        EXPECT_EQ(token.type, correctToken.type);
        EXPECT_EQ(token.literal, correctToken.literal);
    }
}

