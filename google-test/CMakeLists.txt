project(google_test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(google_test_lexer lexer-test.cpp)
target_link_libraries(google_test_lexer lexer_lib)
target_link_libraries(google_test_lexer gtest gtest_main)

add_executable(google_test_parser parser-test.cpp)
target_link_libraries(google_test_parser parser_lib)
target_link_libraries(google_test_parser gtest gtest_main)