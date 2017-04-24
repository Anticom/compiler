#include "TokenNode.hxx"


anticom::TokenNode::TokenNode(std::shared_ptr<anticom::Token> token)
    : token(token) {
};
anticom::TokenNode::TokenNode(std::shared_ptr<anticom::Token> token, children_t children)
    : token(token), children(children) {
};
anticom::TokenNode::~TokenNode() {
};

// getters:
std::shared_ptr<anticom::Token> anticom::TokenNode::getToken() {
    return this->token;
};

anticom::TokenNode::children_t anticom::TokenNode::getChildren() {
    return this->children;
};

// auxiliaries
void anticom::TokenNode::addChild(std::shared_ptr<anticom::TokenNode> node) {
    this->children.push_back(node);
};

void anticom::TokenNode::addChild(std::shared_ptr<anticom::Token> token) {
    std::shared_ptr<anticom::TokenNode> node(new TokenNode(token));
    this->addChild(node);
};
