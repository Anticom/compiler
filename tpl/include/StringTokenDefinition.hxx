#ifndef COMPILER_STRING_TOKEN_DEFINITION_
#define COMPILER_STRING_TOKEN_DEFINITION_

#include <memory>
#include <string>

#include "TokenDefinition.hxx"
#include "Token.hxx"

namespace anticom {

/**
 * Defines a token type via simple string comparision
 */
class StringTokenDefinition : public TokenDefinition {
public:
    StringTokenDefinition(const std::string& id, const std::string& matcher);
    virtual ~StringTokenDefinition();

    // ----- INTERFACE
    const std::string& getId() const override;
    bool matches(std::string& string) override;
    std::shared_ptr<Token> digest(std::string& string) override;
private:
    const std::string id;
    const std::string matcher;
};

}

#endif//COMPILER_STRING_TOKEN_DEFINITION_
