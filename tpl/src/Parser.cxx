#include "Parser.hxx"

#include "constants.hxx"

anticom::Parser::Parser(anticom::ProductionRules productionRules)
    : productionRules(productionRules) {
};
anticom::Parser::~Parser() {
};

std::shared_ptr<anticom::TokenNode> anticom::Parser::parse(anticom::TokenStream& tokenStream) {
    std::shared_ptr<anticom::Token> rootToken(new anticom::Token(anticom::ROOT_TOKEN_TYPE, "<filename>"));
    std::shared_ptr<anticom::TokenNode> rootNode(new anticom::TokenNode(rootToken));

    this->doParse(tokenStream, rootNode);

    return rootNode;
};

void anticom::Parser::doParse(anticom::TokenStream& tokenStream, std::shared_ptr<anticom::TokenNode> node) {
    // TODO
    // bongus for now to get some results
    for(std::shared_ptr<anticom::Token> t : tokenStream) {
        if(t->getType().compare("WS") != 0 && t->getType().compare("NL")) node->addChild(t);
    }
};
