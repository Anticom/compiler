#include "Compiler.hxx"


anticom::Compiler::Compiler(anticom::Lexer lexer, anticom::Parser parser)
    : lexer(lexer), parser(parser) {
};
anticom::Compiler::~Compiler() {

};

std::shared_ptr<anticom::TokenNode> anticom::Compiler::compile(anticom::File& file) {
    anticom::TokenStream tokenStream = this->lexer.lex(file);
    return this->parser.parse(tokenStream);
};
