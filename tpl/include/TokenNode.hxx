#ifndef COMPILER_TOKEN_NODE_
#define COMPILER_TOKEN_NODE_

#include <memory>
#include <list>

#include "Token.hxx"

namespace anticom {

/**
 * Strukturing Tokens into an AST
 */
class TokenNode {
public:
    typedef std::list<std::shared_ptr<TokenNode>> children_t;

    TokenNode(std::shared_ptr<Token> token);
    TokenNode(std::shared_ptr<Token> token, children_t children);
    virtual ~TokenNode();

    // getters:
    std::shared_ptr<Token> getToken();
    children_t getChildren();

    // auxiliaries
    void addChild(std::shared_ptr<TokenNode> node);
    void addChild(std::shared_ptr<Token> token);
private:
    std::shared_ptr<Token> token;
    children_t children;
};

// Moar suggar :)
typedef TokenNode AST;

}

#endif//COMPILER_TOKEN_NODE_
