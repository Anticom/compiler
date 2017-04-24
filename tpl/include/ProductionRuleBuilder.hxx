#ifndef COMPILER_PRODUCTION_RULE_BUILDER_
#define COMPILER_PRODUCTION_RULE_BUILDER_

#include "Token.hxx"

namespace anticom {

// fw-decl for ProductionRuleBuilder
class Token;

class ProductionRuleBuilder {
public:
    ProductionRuleBuilder(Token& token);
    virtual ~ProductionRuleBuilder();

    ProductionRuleBuilder& operator,(Token& token);
    Token& done();
private:
    Token& token;
};

}

#endif//COMPILER_PRODUCTION_RULE_BUILDER_
