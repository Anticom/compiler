#ifndef COMPILER_AST_PRINTER_
#define COMPILER_AST_PRINTER_

#include <memory>
#include <string>

#include "TokenNode.hxx"

namespace anticom {

/**
 * Pretty-prints the AST to console
 * For debugging purposes etc.
 */
class AstPrinter {
public:
    AstPrinter() = delete;

    static void print(std::shared_ptr<TokenNode> rootNode);
private:
    static const unsigned int NUM_INDENT = 2;

    static std::string indent(unsigned int num);
    static void traverse(std::shared_ptr<TokenNode> node, unsigned int currentIndentationLevel);
};

}

#endif//COMPILER_AST_PRINTER_
