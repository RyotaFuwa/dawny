set(HEADER_FILES
        AST/Node.h
        AST/Program.h

        AST/Statement.h
        AST/Block.h
        AST/Let.h
        AST/Return.h
        AST/Assign.h
        AST/ExpressionStatement.h

        AST/Expression.h
        AST/Identifier.h
        AST/Number.h
        AST/Bool.h
        AST/Prefix.h
        AST/Infix.h
        )

set(SOURCE_FILES
        AST/Node.cpp
        AST/Program.cpp

        AST/Statement.cpp
        AST/Block.cpp
        AST/Let.cpp
        AST/Return.cpp
        AST/Assign.cpp
        AST/ExpressionStatement.cpp

        AST/Expression.cpp
        AST/Identifier.cpp
        AST/Number.cpp
        AST/Bool.cpp
        AST/Prefix.cpp
        AST/Infix.cpp
        )

add_library(ast STATIC ${SOURCE_FILES} ${HEADER_FILES})