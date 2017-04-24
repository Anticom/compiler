#ifndef COMPILER_TOKEN_DEFINITION_FACTORY_
#define COMPILER_TOKEN_DEFINITION_FACTORY_

#include "TokenDefinition.hxx"
#include "StringTokenDefinition.hxx"
#include "RegexTokenDefinition.hxx"
#include "LambdaTokenDefinition.hxx"
#include "BoundTokenDefinition.hxx"
#include "ErrorTokenDefinition.hxx"

namespace anticom {

/**
 * Syntastic sugar
 */
class TokenDefinitionFactory {
public:
    TokenDefinitionFactory() = delete;

    static std::shared_ptr<TokenDefinition> create(std::string id, std::string matcher);
    static std::shared_ptr<TokenDefinition> create(std::string id, std::regex matcher);
    static std::shared_ptr<TokenDefinition> create(std::string id, LambdaTokenDefinition::tester_t tester, LambdaTokenDefinition::matcher_t matcher);
    static std::shared_ptr<TokenDefinition> create(std::string id, const std::string& leftDelimitter, const std::string& rightDelimitter, bool multiline = true);
    static std::shared_ptr<TokenDefinition> createErrorTokenDefinition();
};

}

#endif//COMPILER_TOKEN_DEFINITION_FACTORY_
