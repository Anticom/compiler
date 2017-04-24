#include "TokenDefinitionFactory.hxx"


std::shared_ptr<anticom::TokenDefinition> anticom::TokenDefinitionFactory::create(std::string id, std::string matcher) {
    return std::shared_ptr<anticom::TokenDefinition>(new anticom::StringTokenDefinition(id, matcher));
};

std::shared_ptr<anticom::TokenDefinition> anticom::TokenDefinitionFactory::create(std::string id, std::regex matcher) {
    return std::shared_ptr<anticom::TokenDefinition>(new anticom::RegexTokenDefinition(id, matcher));
};

std::shared_ptr<anticom::TokenDefinition> anticom::TokenDefinitionFactory::create(std::string id, anticom::LambdaTokenDefinition::tester_t tester, anticom::LambdaTokenDefinition::matcher_t matcher) {
    return std::shared_ptr<anticom::TokenDefinition>(new anticom::LambdaTokenDefinition(id, tester, matcher));
};

std::shared_ptr<anticom::TokenDefinition> anticom::TokenDefinitionFactory::create(std::string id, const std::string& leftDelimitter, const std::string& rightDelimitter, bool multiline) {
    return std::shared_ptr<anticom::TokenDefinition>(new anticom::BoundTokenDefinition(id, leftDelimitter, rightDelimitter, multiline));
};

std::shared_ptr<anticom::TokenDefinition> anticom::TokenDefinitionFactory::createErrorTokenDefinition() {
  return std::shared_ptr<anticom::TokenDefinition>(new anticom::ErrorTokenDefinition());
};
