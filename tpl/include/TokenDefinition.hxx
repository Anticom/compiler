#ifndef COMPILER_TOKEN_DEFINITION_
#define COMPILER_TOKEN_DEFINITION_

#include <memory>
#include <string>

#include "Token.hxx"

namespace anticom {

/**
 * Defines a token type
 * This is only an interface used by the lexer
 */
class TokenDefinition {
public:
    // TODO move id impl up here
    virtual const std::string& getId() const = 0;

    virtual bool matches(std::string& string) = 0;
    virtual std::shared_ptr<Token> digest(std::string& string) = 0;
};

}

#endif//COMPILER_TOKEN_DEFINITION_
