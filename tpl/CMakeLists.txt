cmake_minimum_required(VERSION 3.2)
project(tpl)
set(TARGET_NAME ${PROJECT_NAME})

#option(BUILD_SHARED_LIBS "Build shared instead of static libs?" ON)

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

    # APPLICATION
    #src/sketch.cxx
    )

#configure_file(${PROJECT_SOURCE_DIR}/hello.go ${PROJECT_BINARY_DIR}/hello.go COPYONLY)

#add_executable(${TARGET_NAME} ${CXX_SOURCES})
add_library(${TARGET_NAME} ${CXX_SOURCES})
target_include_directories(${TARGET_NAME} PUBLIC ${CXX_INCLUDE_DIR})
set_target_properties(${TARGET_NAME}
    PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED TRUE)
