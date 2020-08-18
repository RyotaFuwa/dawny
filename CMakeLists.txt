cmake_minimum_required(VERSION 3.17)
project(dawny)

set(CMAKE_CXX_STANDARD 14)


# main
set(SOURCE_FILES main.cpp)
add_executable(dawny ${SOURCE_FILES})

# lexer, repl
include_directories(token)
include_directories(lexer)
include_directories(repl)

add_subdirectory(lexer)
add_subdirectory(repl)

# main link to library
target_link_libraries(dawny lexer_lib)

# test
add_subdirectory(google-test)

