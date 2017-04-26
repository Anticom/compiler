cmake_minimum_required(VERSION 3.2)
project(tpl)
set(TARGET_NAME ${PROJECT_NAME})

enable_testing()
find_package(GTest REQUIRED)

# CONFIG
option(BUILD_SHARED_LIBS "Build shared instead of static libs?" ON)

if(COVERAGE)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        # using Clang
        set(CXX_FLAGS "-coverage -O0")
    elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        # using GCC
        set(CXX_FLAGS "-fprofile-arcs -ftest-coverage -fPIC -O0")
    endif()
endif()

# PROJECT FILES
set(CXX_INCLUDE_DIR
    ${PROJECT_SOURCE_DIR}/include)

set(CXX_SOURCES
    # GENERAL
    src/File.cxx
    src/Token.cxx

    # LEXING
    src/TokenDefinition.cxx
    src/StringTokenDefinition.cxx
    src/RegexTokenDefinition.cxx    #this one is broken (because STL regex is!)
    src/LambdaTokenDefinition.cxx
    src/BoundTokenDefinition.cxx
    src/ErrorTokenDefinition.cxx
    src/TokenDefinitionFactory.cxx

    src/TokenStream.cxx
    src/Lexer.cxx

    # PARSING
    src/TokenNode.cxx
    src/SymbolTable.cxx
    src/ProductionRule.cxx
    src/ProductionRules.cxx
    src/ProductionRuleBuilder.cxx
    src/Parser.cxx

    src/Compiler.cxx

    # DEV TOOLS
    src/TokenStreamPrinter.cxx
    src/AstPrinter.cxx
    )

# BUILDING
add_library(${TARGET_NAME} ${CXX_SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${CXX_INCLUDE_DIR})
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED TRUE)

# TESTS
set(CXX_TEST_SOURCES
    test/testAstPrinter.cxx)

set(CXX_TEST_INCLUDE_DIR ${CXX_INCLUDE_DIR})

add_executable(AllTests ${CXX_TEST_SOURCES})
target_link_libraries(AllTests ${TARGET_NAME})
target_include_directories(AllTests PRIVATE ${CXX_TEST_INCLUDE_DIR})
set_target_properties(AllTests
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED TRUE)

GTEST_ADD_TESTS(AllTests "" AUTO)