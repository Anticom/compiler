#include "LambdaTokenDefinition.hxx"

anticom::LambdaTokenDefinition::LambdaTokenDefinition(const std::string& id, tester_t tester, matcher_t matcher)
    : id(id), tester(tester), matcher(matcher) {

};

anticom::LambdaTokenDefinition::~LambdaTokenDefinition() {

};

// ----- INTERFACE
const std::string& anticom::LambdaTokenDefinition::getId() const {
  return this->id;
};

bool anticom::LambdaTokenDefinition::matches(std::string& string) {
    return this->tester(string);
};
std::shared_ptr<anticom::Token> anticom::LambdaTokenDefinition::digest(std::string& string) {
    return this->matcher(string);
};
