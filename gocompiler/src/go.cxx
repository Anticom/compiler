#include <memory>

#include "Compiler.hxx"
#include "AstPrinter.hxx"

#include "syntax.hxx"
#include "grammar.hxx"

using namespace anticom;

int main(int argc, char** argv) {
    File file("./hello.go");

    std::list<std::shared_ptr<Token>> terminalTokens;
    auto syntax = getGoSyntax();
    auto grammar = getGoGrammar(terminalTokens);

    Compiler compiler = Compiler(syntax, grammar);
    std::shared_ptr<AST> ast = compiler.compile(file);

    AstPrinter::print(ast);

    return 0;
};

