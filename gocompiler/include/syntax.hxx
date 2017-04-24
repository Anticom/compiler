#ifndef GO_SYNTAX_
#define GO_SYNTAX_

#include "TokenDefinitionFactory.hxx"
#include "Lexer.hxx"

namespace anticom {

Lexer::config_t getGoSyntax() {
    Lexer::config_t tokendefinitions;
    
    // ---string literal
    //tokendefinitions.push_back(TokenDefinitionFactory::create("STRING_INTERPRETED", std::regex("^\"(.*)\"",         std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    //tokendefinitions.push_back(TokenDefinitionFactory::create("COMMENT_MULTI",  std::regex("^\\/\\*(.*)\\*\\/", std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    //tokendefinitions.push_back(TokenDefinitionFactory::create("COMMENT_SINGLE", std::regex("^//(.*)",       std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    
    tokendefinitions.push_back(TokenDefinitionFactory::create("STRING_RAW", "`", "`"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("STRING_INTERPRETED", "\"", "\"", false));
    tokendefinitions.push_back(TokenDefinitionFactory::create("RUNE_LIT", "'", "'", false));

    // ---comments
    tokendefinitions.push_back(TokenDefinitionFactory::create("COMMENT_MULTI", "/*", "*/"));
    tokendefinitions.push_back(
        TokenDefinitionFactory::create(
            "COMMENT_SINGLE",
            [](std::string& string) -> bool {
                return string.find("//") == 0;
            },
            [](std::string& string) -> std::shared_ptr<Token> {
                std::string::size_type stoppingPosition = string.find_first_of("\r\n");
                std::string token = string.substr(2, stoppingPosition - 2);

                // reduce the string
                string = std::string(string, stoppingPosition);

                return std::shared_ptr<Token>(new Token("COMMENT_SINGLE", token));
            }
        )
    );
    
    //tokendefinitions.push_back(TokenDefinitionFactory::create("WS",     std::regex("^(\\s+)",           std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    tokendefinitions.push_back(TokenDefinitionFactory::create("WS", " "));
    tokendefinitions.push_back(TokenDefinitionFactory::create("WS", "\t"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("NL", "\r\n"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("NL", "\n"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("NL", "\r"));

    // ---Keywords:
    tokendefinitions.push_back(TokenDefinitionFactory::create("BREAK",       "break"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CASE",        "case"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CHAN",        "chan"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CONST",       "const"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CONTINUE",    "continue"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DEFAULT",     "default"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DEFER",       "defer"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("ELSE",        "else"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("FALLTHROUGH", "fallthrough"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("FOR",         "for"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("FUNC",        "func"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("GO",          "go"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("GOTO",        "goto"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("IF",          "if"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("IMPORT",      "import"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("INTERFACE",   "interface"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MAP",         "map"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("PACKAGE",     "package"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("RANGE",       "range"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("RETURN",      "return"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SELECT",      "select"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("STRUCT",      "struct"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SWITCH",      "switch"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("TYPE",        "type"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("VAR",         "var"));

    // ---Operators and Delimiters:
    tokendefinitions.push_back(TokenDefinitionFactory::create("SHIFTL_EQ",  "<<="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SHIFTR_EQ",  ">>="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_CLR_EQ", "&^="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("EXPAND",     "..."));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SHIFTL",     "<<"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SHIFTR",     ">>"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_CLR",    "&^"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("PLUS_EQ",    "+="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MINUS_EQ",   "-="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MUL_EQ",     "*="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DIV_EQ",     "/="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MOD_EQ",     "%="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_AND_EQ", "&="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_OR_EQ",  "|="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_XOR_EQ", "^="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("AND",        "&&"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("OR",         "||"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SEND",       "<-"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("INC",        "++"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DEC",        "--"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CMP",        "=="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("NE",         "!="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("LE",         "<="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("GE",         ">="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("ASSIGN",     ":="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("PLUS",       "+"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MINUS",      "-"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MUL",        "*"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DIV",        "/"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("MOD",        "%"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_AND",    "&"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_OR",     "|"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BIN_XOR",    "^"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("LT",         "<"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("GT",         ">"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("EQ",         "="));
    tokendefinitions.push_back(TokenDefinitionFactory::create("NOT",        "!"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("PRENL",      "("));
    tokendefinitions.push_back(TokenDefinitionFactory::create("PRENR",      ")"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BRACL",      "["));
    tokendefinitions.push_back(TokenDefinitionFactory::create("BRACR",      "]"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CURLL",      "{"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("CURLR",      "}"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("COMMA",      ","));
    tokendefinitions.push_back(TokenDefinitionFactory::create("DOT",        "."));
    tokendefinitions.push_back(TokenDefinitionFactory::create("COLON",      ":"));
    tokendefinitions.push_back(TokenDefinitionFactory::create("SCOLON",     ";"));

    // ---Identifiers:
    //tokendefinitions.push_back(TokenDefinitionFactory::create("IDENTIFIER", std::regex("^([a-zA-Z_][a-zA-Z0-9_]*)", std::regex_constants::extended | std::regex_constants::optimize)));
    tokendefinitions.push_back(
        TokenDefinitionFactory::create(
            "IDENTIFIER",
            [](std::string& string) -> bool {
                return string.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0;
            },
            [](std::string& string) -> std::shared_ptr<Token> {
                // https://groups.google.com/d/msg/golang-nuts/VM0vomFPphg/gLFo-IuCJtQJ
                static const std::uint8_t MAX_IDENTIFIER_LENGTH = 255;
                std::uint8_t currentLength = 0; 
                do {
                    currentLength++;
                } while((string.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_", currentLength) == currentLength) && (currentLength < MAX_IDENTIFIER_LENGTH));

                // TODO check identifier too long

                std::string token = string.substr(0, currentLength);

                // reduce the string
                string = std::string(string, currentLength);

                return std::shared_ptr<Token>(new Token("IDENTIFIER", token));
            }
        )
    );
    
    // ---Literals:
    //tokendefinitions.push_back(TokenDefinitionFactory::create("LITERAL_INT",    std::regex("^([0-9]+)",      std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    // mapping hex literals to int token type aswell
    //tokendefinitions.push_back(TokenDefinitionFactory::create("LITERAL_INT",    std::regex("(^0x[0-9a-fA-F]+)", std::regex_constants::ECMAScript | std::regex_constants::optimize | std::regex_constants::icase)));
    //tokendefinitions.push_back(TokenDefinitionFactory::create("LITERAL_FLOAT",  std::regex("^([0-9]+)",      std::regex_constants::ECMAScript | std::regex_constants::optimize)));
    //tokendefinitions.push_back(TokenDefinitionFactory::create("LITERAL_RUNE",   std::regex("^([0-9]+)",      std::regex_constants::ECMAScript | std::regex_constants::optimize)));

    // ---Misc:

    tokendefinitions.push_back(TokenDefinitionFactory::createErrorTokenDefinition());

    return tokendefinitions;
};

}

#endif//GO_SYNTAX_
