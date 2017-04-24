#include "RegexTokenDefinition.hxx"

#include <iostream>

anticom::RegexTokenDefinition::RegexTokenDefinition(const std::string& id, std::regex matcher)
    : id(id), matcher(matcher) {

};

anticom::RegexTokenDefinition::~RegexTokenDefinition() {

};

// ----- INTERFACE
const std::string& anticom::RegexTokenDefinition::getId() const {
  return this->id;
}

bool anticom::RegexTokenDefinition::matches(std::string& string) {
    std::cout << "Trying to apply [" << this->id << "] to [" << string.substr(0, string.find_first_of(" \r\n\t")) << " ...]" << std::endl;
    std::smatch matches;
    return std::regex_search(string, matches, matcher);
};

std::shared_ptr<anticom::Token> anticom::RegexTokenDefinition::digest(std::string& string) {
    std::smatch matches;
    std::regex_search(string, matches, matcher);
    std::string token = matches.str(1);

    // reduce the string
    string = std::string(string, matches.str(0).length());

    return std::shared_ptr<anticom::Token>(new anticom::Token(this->id, token));
};
