#ifndef COMPILER_SYMBOL_TABLE_
#define COMPILER_SYMBOL_TABLE_

#include <memory>
#include <unordered_map>
#include <string>

#include "Token.hxx"

namespace anticom {

// TODO Since symbols are scoped, each TokenNode probably needs an (optional) symbol table attached to it so we can walk the tree to upwards to all defined symbols in the current node's scope
class SymbolTable : std::unordered_map<std::shared_ptr<Token>, std::string> {};

}

#endif//COMPILER_SYMBOL_TABLE_
