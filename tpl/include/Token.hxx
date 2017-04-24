#ifndef COMPILER_TOKEN_
#define COMPILER_TOKEN_

#include <string>

#include "ProductionRuleBuilder.hxx"

namespace anticom {

// fw-decl for Token
class ProductionRuleBuilder;

/**
 * Holding the explicit tokens along side with meta information
 */
class Token {
public:
    Token(std::string type, std::string value);
    Token(std::string type, std::string value, unsigned int row, unsigned int col);
    Token(std::string type, std::string value, std::string filename, unsigned int row, unsigned int col);
    virtual ~Token();

    // getters:
    std::string& getType();
    virtual std::string& getValue();
    std::string& getFilename();
    unsigned int& getRow();
    unsigned int& getCol();

    // Operator magic:
    ProductionRuleBuilder operator<<(std::string& tokenType);
    ProductionRuleBuilder operator<<(Token& token);
private:
    std::string type;
    std::string value;
    std::string filename;
    unsigned int row;
    unsigned int col;
};

}

#endif//COMPILER_TOKEN_
