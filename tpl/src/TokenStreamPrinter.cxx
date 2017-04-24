#include "TokenStreamPrinter.hxx"

#include <memory>
#include <iostream>

#include "Token.hxx"

void anticom::TokenStreamPrinter::print(anticom::TokenStream ts) {
    for(std::shared_ptr<anticom::Token> t : ts) {
        std::cout << "<" << t->getType()/* << "," << t->getValue()*/ << ">";
    }
    std::cout << std::endl;
};

// TODO somewhat buggy since Tokens might already strip meta-symbols
//  --> for example comments strip '//' and '/* ... */'
void anticom::TokenStreamPrinter::reconstruct(anticom::TokenStream ts) {
    for(std::shared_ptr<anticom::Token> t : ts) {
        std::cout << t->getValue();
    }
};
