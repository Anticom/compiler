#ifndef COMPILER_PRODUCTION_RULE_
#define COMPILER_PRODUCTION_RULE_

#include <memory>
#include <list>
#include <string>

#include "TokenStream.hxx"
#include "TokenNode.hxx"

namespace anticom {

// TODO
class ProductionRule {
public:
    typedef std::list<std::string> bucket_t;

    ProductionRule(std::string& lhs, bucket_t& rhs);
    virtual ~ProductionRule();

    bool matches(TokenStream& tokenStream);
    bool digest(TokenStream& tokenStream, std::shared_ptr<TokenNode> node);
private:
    // template types (string) are the Identifiers of the Tokens (--> type)
    std::string lhs;
    std::list<std::string> rhs;
};

}

#endif//COMPILER_PRODUCTION_RULE_
