#include "Lexer.hxx"

#include <sstream>

anticom::Lexer::Lexer(anticom::Lexer::config_t config)
    : config(config) {

};

anticom::Lexer::~Lexer() {

};

anticom::TokenStream anticom::Lexer::lex(anticom::File& file) {
    std::string filecontents = file.read();
    anticom::TokenStream tokenStream;

    while(!filecontents.empty()) {
        bool hasMatch = false;
        for(std::shared_ptr<anticom::TokenDefinition> td : this->config) {
            if(td->matches(filecontents)) {
                std::shared_ptr<anticom::Token> token = td->digest(filecontents);
                tokenStream.push_back(token);
                hasMatch = true;
                break;
            }
        }

        if(!hasMatch) {
            std::stringstream ss;
            ss << "Lexer: Unable to digest token ["
                << filecontents.substr(0, filecontents.find_first_of(" \n\r\t"))
                << "]";
            throw std::logic_error(ss.str());
        }
    }

    file.close();

    return tokenStream;
};
