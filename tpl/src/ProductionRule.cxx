#include "ProductionRule.hxx"


anticom::ProductionRule::ProductionRule(std::string& lhs, anticom::ProductionRule::bucket_t& rhs)
    : lhs(lhs), rhs(rhs) {};
anticom::ProductionRule::~ProductionRule() {};

bool anticom::ProductionRule::matches(anticom::TokenStream& tokenStream) {
    // TODO
    return false;
}

bool anticom::ProductionRule::digest(anticom::TokenStream& tokenStream, std::shared_ptr<anticom::TokenNode> node) {
    // TODO
    return false;
}
