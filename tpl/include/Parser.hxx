#ifndef COMPILER_PARSER_
#define COMPILER_PARSER_

#include <memory>

#include "TokenStream.hxx"
#include "TokenNode.hxx"
#include "ProductionRules.hxx"

#include "SymbolTable.hxx"

namespace anticom {

/**
 * Parses a Token file into an AST
 */
class Parser {
public:
    Parser(ProductionRules productionRules);
    virtual ~Parser();

    std::shared_ptr<TokenNode> parse(TokenStream& tokenStream);
private:
    ProductionRules productionRules;
    SymbolTable symbolTable;
    
    void doParse(TokenStream& tokenStream, std::shared_ptr<TokenNode> node);
};

}

#endif//COMPILER_PARSER_
