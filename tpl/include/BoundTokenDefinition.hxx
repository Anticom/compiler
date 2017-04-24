#ifndef COMPILER_BOUND_TOKEN_DEFINITION_
#define COMPILER_BOUND_TOKEN_DEFINITION_

#include <memory>
#include <string>

#include "TokenDefinition.hxx"
#include "Token.hxx"

namespace anticom {

/**
 * TODO
 */
class BoundTokenDefinition : public TokenDefinition {
public:
    BoundTokenDefinition(const std::string& id, const std::string& leftDelimitter, const std::string& rightDelimitter, bool multiline);
    virtual ~BoundTokenDefinition();

    // ----- INTERFACE
    const std::string& getId() const override;
    bool matches(std::string& string) override;

    std::shared_ptr<Token> digest(std::string& string) override;
private:
    static const std::string NL_CHARS;

    const std::string id;
    const std::string leftDelimitter;
    const std::string rightDelimitter;
    const unsigned int leftDelimitterLength;
    const unsigned int rightDelimitterLength;
    const bool multiline;
};

}

#endif//COMPILER_BOUND_TOKEN_DEFINITION_
