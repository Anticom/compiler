#include "ProductionRuleBuilder.hxx"

anticom::ProductionRuleBuilder::ProductionRuleBuilder(Token& token)
    : token(token) {

};

anticom::ProductionRuleBuilder::~ProductionRuleBuilder() {

};


anticom::ProductionRuleBuilder& anticom::ProductionRuleBuilder::operator,(Token& token) {
    return *this;
};

anticom::Token& anticom::ProductionRuleBuilder::done() {
    return this->token;
};
