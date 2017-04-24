#include "ErrorTokenDefinition.hxx"

anticom::ErrorTokenDefinition::ErrorTokenDefinition() {

};

anticom::ErrorTokenDefinition::~ErrorTokenDefinition() {

};

// ----- INTERFACE
const std::string& anticom::ErrorTokenDefinition::getId() const {
  return ID;
}

// ErrorTokenDefinition will *always* match to fire on error condition!
bool anticom::ErrorTokenDefinition::matches(std::string& string) {
  return true;
};

std::shared_ptr<anticom::Token> anticom::ErrorTokenDefinition::digest(std::string& string) {
    // extract token untill next whitespace
    std::string token = string.substr(0, string.find_first_of(" \r\n\t"));
    // reduce the string
    string = std::string(string, token.length());
    
    //std::cout << "ERROR: unmatched token: [" << token << "]" << std::endl;

    return std::shared_ptr<anticom::Token>(new anticom::Token("ERROR", token));
};

const std::string anticom::ErrorTokenDefinition::ID = "ERROR";
