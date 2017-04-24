#ifndef COMPILER_LEXER_
#define COMPILER_LEXER_

#include <memory>
#include <string>

#include "File.hxx"
#include "Token.hxx"
#include "TokenDefinition.hxx"
#include "TokenStream.hxx"

namespace anticom {

/**
 * Lexes a string file into tokens
 * Using a list of TokenDefinitions for config
 */
class Lexer {
public:
    typedef std::list<std::shared_ptr<TokenDefinition>> config_t;

    Lexer(config_t config);
    virtual ~Lexer();

    TokenStream lex(File& file);
private:
    config_t config;
};

}

#endif//COMPILER_LEXER_
