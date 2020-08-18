project(lexer_lib)

set(HEADER_FILES
        Lexer.h
        )

set(SOURCE_FILES
        Lexer.cpp
        )

add_library(lexer_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})