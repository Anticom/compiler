#ifndef COMPILER_COMPILER_
#define COMPILER_COMPILER_

#include <memory>

#include "File.hxx"
#include "TokenStream.hxx"
#include "TokenNode.hxx"

#include "Lexer.hxx"
#include "Parser.hxx"

namespace anticom {

/**
 * Putting it all together
 */
class Compiler {
public:
    Compiler(Lexer lexer, Parser parser);
    virtual ~Compiler();

    std::shared_ptr<TokenNode> compile(File& file);
private:
    Lexer lexer;
    Parser parser;
};

}

#endif//COMPILER_COMPILER_
