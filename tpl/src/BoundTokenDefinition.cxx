#include "BoundTokenDefinition.hxx"

anticom::BoundTokenDefinition::BoundTokenDefinition(const std::string& id, const std::string& leftDelimitter, const std::string& rightDelimitter, bool multiline)
    : id(id),
      leftDelimitter(leftDelimitter),
      rightDelimitter(rightDelimitter),
      leftDelimitterLength(leftDelimitter.length()),
      rightDelimitterLength(rightDelimitter.length()),
      multiline(multiline) {

}; 

anticom::BoundTokenDefinition::~BoundTokenDefinition() {

};

// ----- INTERFACE
const std::string& anticom::BoundTokenDefinition::getId() const {
  return this->id;
}

bool anticom::BoundTokenDefinition::matches(std::string& string) {
    bool startingCondition = string.find(this->leftDelimitter) == 0;
    if(startingCondition) {
        if(this->multiline) {
            return string.find(this->rightDelimitter, this->leftDelimitterLength) != std::string::npos;
        } else {
            std::string::size_type nextNlPosition = string.find_first_of(NL_CHARS, this->leftDelimitterLength);
            std::string::size_type stoppingPosition = string.find(this->rightDelimitter, this->leftDelimitterLength);
            if(stoppingPosition == std::string::npos) return false;
            // guaranteed right delimitter
            if(nextNlPosition == std::string::npos) return stoppingPosition != std::string::npos;
            // guaranteed right delimitter AND NL
            return stoppingPosition < nextNlPosition;
        }
    }
    return false;
};

std::shared_ptr<anticom::Token> anticom::BoundTokenDefinition::digest(std::string& string) {
    std::string::size_type stoppingPosition = string.find(this->rightDelimitter, this->leftDelimitterLength);
    std::string token = string.substr(this->leftDelimitterLength, stoppingPosition - this->rightDelimitterLength);

    // reduce the string
    string = std::string(string, stoppingPosition + this->rightDelimitterLength);

    return std::shared_ptr<anticom::Token>(new anticom::Token(this->id, token));
};

const std::string anticom::BoundTokenDefinition::NL_CHARS = "\r\n";
