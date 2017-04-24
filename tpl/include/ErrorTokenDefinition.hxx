#ifndef COMPILER_ERROR_TOKEN_DEFINITION_
#define COMPILER_ERROR_TOKEN_DEFINITION_

#include <memory>
#include <string>

#include "TokenDefinition.hxx"
#include "Token.hxx"

namespace anticom {

/**
 * Special TokenDefinition
 * Used by the lexer to indicate, that all other TokenDefinitions didn't match
 * This is a critical error because the lexer *CAN NOT* continue
 */
class ErrorTokenDefinition : public TokenDefinition {
public:
    ErrorTokenDefinition();
    virtual ~ErrorTokenDefinition();
    
    // ----- INTERFACE
    const std::string& getId() const override;
    bool matches(std::string& string) override;

    std::shared_ptr<Token> digest(std::string& string) override;
private:
    static const std::string ID;
};

}

#endif//COMPILER_ERROR_TOKEN_DEFINITION_
