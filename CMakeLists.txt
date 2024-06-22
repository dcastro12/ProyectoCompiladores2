cmake_minimum_required(VERSION 2.6)
project(lpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(FLEX)
find_package(BISON)


find_program (TREECC treecc
              PATHS /usr /usr/local /opt /opt/local $ENV{TREECC_DIR}
              PATH_SUFFIXES treecc/bin bin )

if (TREECC)
    message(STATUS "Using treecc executable ${TREECC}")
else(TREECC)
    message(FATAL_ERROR "treecc was not found. Try setting TREECC_DIR environment variable")
endif(TREECC)


add_custom_command (
  OUTPUT Mini_LPP_Ast.cpp Mini_LPP_Ast.hpp
  COMMAND ${TREECC} -o Mini_LPP_Ast.cpp -h Mini_LPP_Ast.hpp ${PROJECT_SOURCE_DIR}/Mini_LPP_Ast.tc
  MAIN_DEPENDENCY ${PROJECT_SOURCE_DIR}/Mini_LPP_Ast.tc
  )


FLEX_TARGET(Mini_LPP_Lexer Mini_LPP_LexerImpl.l
            ${CMAKE_CURRENT_BINARY_DIR}/Mini_LPP_LexerImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/Mini_LPP_LexerImpl.hpp
            )

BISON_TARGET(Mini_LPP_Parser Mini_LPP_ParserImpl.y
            ${CMAKE_CURRENT_BINARY_DIR}/Mini_LPP_ParserImpl.cpp
            DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/Mini_LPP_ParserImpl.hpp
            )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(${PROJECT_NAME}
    ${FLEX_Mini_LPP_Lexer_OUTPUTS}
    ${BISON_Mini_LPP_Parser_OUTPUTS}
    Mini_LPP_Parser.hpp
    Mini_LPP_Parser.cpp
    Mini_LPP_Lexer.hpp
    Mini_LPP_Lexer.cpp
    Mini_LPP_Ast.hpp
    Mini_LPP_Ast.cpp
    Mini_LPP_main.cpp
 )