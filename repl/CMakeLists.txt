add_executable(repl main.cpp REPL.cpp REPL.h)
target_link_libraries(repl lexer_lib)
