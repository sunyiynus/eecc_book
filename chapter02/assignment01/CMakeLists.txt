cmake_minimum_required(VERSION 3.16)
project(assignment01)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
    message(STATUS "Configuring on/for IBM AIX")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()

add_custom_target(pl0scaner
    ALL
    COMMAND
        flex ${CMAKE_CURRENT_SOURCE_DIR}/pl0.l
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT
        "Generating flex lexer lex.yy.c ..")

add_executable(pl0lexer "")
target_sources(pl0lexer
    PRIVATE
        lex.yy.c
        ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

enable_testing()

add_test(NAME ts01 COMMAND pl0lexer ${CMAKE_SOURCE_DIR}/tests/testcase01)
add_test(NAME ts02 COMMAND pl0lexer ${CMAKE_SOURCE_DIR}/tests/testcase02)
add_test(NAME ts03 COMMAND pl0lexer ${CMAKE_SOURCE_DIR}/tests/testcase03)
add_test(NAME ts04 COMMAND pl0lexer ${CMAKE_SOURCE_DIR}/tests/testcase04)