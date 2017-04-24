#include "StringTokenDefinition.hxx"

anticom::StringTokenDefinition::StringTokenDefinition(const std::string& id, const std::string& matcher)
    : id(id), matcher(matcher) {

};

anticom::StringTokenDefinition::~StringTokenDefinition() {

};

// ----- INTERFACE
const std::string& anticom::StringTokenDefinition::getId() const {
  return this->id;
};

bool anticom::StringTokenDefinition::matches(std::string& string) {
    return string.find(matcher) == 0;
};

std::shared_ptr<anticom::Token> anticom::StringTokenDefinition::digest(std::string& string) {
    // reduce the string
    string = std::string(string, this->matcher.length());
    return std::shared_ptr<anticom::Token>(new anticom::Token(this->id, this->matcher));
};
