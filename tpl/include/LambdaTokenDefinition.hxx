#ifndef COMPILER_LAMBDA_TOKEN_DEFINITION_
#define COMPILER_LAMBDA_TOKEN_DEFINITION_

#include <functional>
#include <memory>
#include <string>

#include "TokenDefinition.hxx"
#include "Token.hxx"

namespace anticom {

/**
 * Defines a token type via callbacks
 */
class LambdaTokenDefinition : public TokenDefinition {
public:
    typedef std::function<bool(std::string&)> tester_t;
    typedef std::function<std::shared_ptr<Token>(std::string&)> matcher_t;

    LambdaTokenDefinition(const std::string& id, tester_t tester, matcher_t matcher);
    virtual ~LambdaTokenDefinition();
    
    // ----- INTERFACE
    const std::string& getId() const override;
    bool matches(std::string& string) override;
    std::shared_ptr<Token> digest(std::string& string) override;
private:
    const std::string id;
    tester_t tester;
    matcher_t matcher;
};

}

#endif//COMPILER_LAMBDA_TOKEN_DEFINITION_
