//
// Created by Ryota Fuwa on 2020/08/20.
//

#include <iostream>
#include <gtest/gtest.h>
#include <Parser.h>

TEST(ParserTest, LetStatement) {
    Parser::Parser parser = Parser::Parser();
    struct test {
        test(std::string input, std::string ident, std::string v) : input{input}, ident{ident}, value{v} {};
        std::string input;
        std::string ident;
        std::string value;
    };
    test tests[] = {
            test("let x = 7;", "x", "7"),
            test("let y = true;", "y", "true"),
            test("let foobar = 52.34;", "foobar", "52.34"),
    };
    for(int i= 0; i < 3; i++) {
        const Program *program = parser.Parse(tests[i].input);
        const Statement *statement = program->statements[0];
        std::cout << tests[i].input << " -> " << statement->ToString() << std::endl;
        ASSERT_EQ(statement->type, NodeType::LET);
        const Let *let = (Let *) statement;
        EXPECT_EQ(tests[i].ident, let->ident->value);
        EXPECT_EQ(tests[i].value, let->expression->ToString());
    }
}

TEST(ParserTest, ReturnStatement) {
    Parser::Parser parser = Parser::Parser();
    struct test {
        test(std::string input, std::string v) : input{input}, returnValue(v) {}
        std::string input;
        std::string returnValue;
    };
    test tests[] = {
            test("return x;", "x"),
            test("return true;", "true"),
            test("return 52.34;", "52.34"),
    };
    for(int i= 0; i < 3; i++) {
        const Program *program = parser.Parse(tests[i].input);
        const Statement *statement = program->statements[0];
        std::cout << tests[i].input << " -> " << statement->ToString() << std::endl;
        ASSERT_EQ(statement->type, NodeType::RETURN);
        const Return *return_ = (Return *) statement;
        EXPECT_EQ(tests[i].returnValue, return_->returnValue->ToString());
    }
}

TEST(ParserTest, AssignStatement) {
    Parser::Parser parser = Parser::Parser();
    struct test {
        test(std::string input, std::string ident, std::string op, std::string v) : input{input}, ident{ident}, op{op}, value{v} {};
        std::string input;
        std::string ident;
        std::string op;
        std::string value;
    };
    test tests[] = {
            test("x = 7;", "x", "=", "7"),
            test("y += 2.3;", "y", "+=", "2.3"),
            test("foobar *= 52.34;", "foobar", "*=", "52.34"),
    };
    for(int i= 0; i < 3; i++) {
        const Program *program = parser.Parse(tests[i].input);
        const Statement *statement = program->statements[0];
        std::cout << tests[i].input << " -> " << statement->ToString() << std::endl;
        ASSERT_EQ(statement->type, NodeType::ASSIGN);
        const Assign *let = (Assign *) statement;
        EXPECT_EQ(tests[i].ident, let->ident->value);
        EXPECT_EQ(tests[i].op, let->op);
        EXPECT_EQ(tests[i].value, let->expression->ToString());
    }
}

TEST(ParserTest, ExpressionStatement) {
}
