#include "Token.hxx"

anticom::Token::Token(std::string type, std::string value)
    : type(type),
      value(value),
      filename("annonymous"),
      row(0),
      col(0) {

};

anticom::Token::Token(std::string type, std::string value, unsigned int row, unsigned int col)
    : type(type),
      value(value),
      filename("annonymous"),
      row(row),
      col(col) {

};

anticom::Token::Token(std::string type, std::string value, std::string filename, unsigned int row, unsigned int col)
    : type(type),
      value(value),
      filename(filename),
      row(row),
      col(col) {

};

anticom::Token::~Token() {

};

// getters:
std::string& anticom::Token::getType() {
    return this->type;
};

std::string& anticom::Token::getValue() {
    return this->value;
};

std::string& anticom::Token::getFilename() {
    return this->filename;
};

unsigned int& anticom::Token::getRow() {
    return this->row;
};

unsigned int& anticom::Token::getCol() {
    return this->col;
};

// Operator magic:

anticom::ProductionRuleBuilder anticom::Token::operator<<(std::string& tokenType) {
    Token t(tokenType, "");
    return ProductionRuleBuilder(t);
};

anticom::ProductionRuleBuilder anticom::Token::operator<<(Token& token) {
    return ProductionRuleBuilder(token);
};

