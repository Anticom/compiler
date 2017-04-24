#include "AstPrinter.hxx"

#include <iostream>
#include <sstream>

void anticom::AstPrinter::print(std::shared_ptr<anticom::TokenNode> rootNode) {
    traverse(rootNode, 0);
};

std::string anticom::AstPrinter::indent(unsigned int num) {
    std::stringstream ss;
    for(int i = 0; i < num; i++) {
        ss << " ";
    }
    return ss.str();
};

void anticom::AstPrinter::traverse(std::shared_ptr<anticom::TokenNode> node, unsigned int currentIndentationLevel) {
    // escape newlines when printing
    std::string value = (node->getToken()->getValue().compare("\n") == 0)? "\\n" : node->getToken()->getValue();

    std::cout << indent(currentIndentationLevel) << "[" << node->getToken()->getType() << " : " << value << "]" << std::endl;
    for(std::shared_ptr<anticom::TokenNode> child : node->getChildren()) {
        traverse(child, (currentIndentationLevel + NUM_INDENT));
    }
};

const unsigned int NUM_INDENT = 2;
