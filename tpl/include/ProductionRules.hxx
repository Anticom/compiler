#ifndef COMPILER_PRODUCTION_RULES_
#define COMPILER_PRODUCTION_RULES_

#include <unordered_map>
#include <string>

#include "ProductionRule.hxx"

namespace anticom {

class ProductionRules : public std::unordered_map<std::string, ProductionRule::bucket_t> {};

}

#endif//COMPILER_PRODUCTION_RULES_
