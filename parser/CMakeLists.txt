project(parser_lib)

set(HEADER_FILES
        Parser.h
        )

set(SOURCE_FILES
        Parser.cpp
        )

add_library(parser_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(parser_lib ast lexer_lib)