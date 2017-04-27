#ifndef GO_GRAMMAR_
#define GO_GRAMMAR_

#include <iostream>
#include <memory>
#include <unordered_map>

#include "Token.hxx"
#include "Lexer.hxx"

namespace anticom {

/**
 * Execution plan for Top-Down parser
 */
class ExecutionPlan {
public:
    ExecutionPlan() {};
    virtual ~ExecutionPlan() {};

    // --- API:
    virtual std::shared_ptr<TokenNode> execute() {
        // TODO
        return std::shared_ptr<TokenNode>(new TokenNode(
            std::shared_ptr<Token>(new Token("TODO", "TODO"))
        ));
    };
};

class ReachedTerminalExecutionPlan {
public:
    ReachedTerminalExecutionPlan(std::shared_ptr<Token> token) : token(token) {

    };
    virtual std::shared_ptr<TokenNode> execute() {
        return std::shared_ptr<TokenNode>(new TokenNode(token));
    };
private:
    std::shared_ptr<Token> token;
};

/**
 * MAGIC DSL WRAPPER
 */
class ProductionDescription {
public:
    ProductionDescription(std::string teststring) {
        std::cout << "received: " << teststring << std::endl;
    };
    virtual ~ProductionDescription() {

    };
private:
};

/**
 * Wrapper arround Token so we get operator=
 */
class TokenProxy {
public:
    TokenProxy(std::shared_ptr<Token> t) : token(t) {};
    ~TokenProxy() {};

    // Operator magic
    // TODO can we utilize implicit constructor conversion here?
    TokenProxy& operator=(ProductionDescription pd) {
        std::cout << "Assignment on proxy triggered" << std::endl;
        return *this; 
    };
private:
    std::shared_ptr<Token> token;
};

/**
 * Container used by ProductionManager
 */
class ProductionMap : public std::unordered_multimap<std::string, ExecutionPlan> {};

/**
 * Central manager for production rules
 */
class ProductionManager {
public:
    ProductionManager(std::list<std::shared_ptr<Token>>& terminalTokens) : tokens(terminalTokens) {
        // TODO create ReachedTerminalExecutionPlan's and feed in terminals
    };
    virtual ~ProductionManager() {};

    TokenProxy def(std::string tokenType) {
        std::shared_ptr<Token> token;
        if(this->hasTokenType(tokenType)) {
            token = this->lookupToken(tokenType);
        } else {
            token = this->createToken(tokenType);
        }

        std::cout << "Creating proxy for tokenType [" << tokenType << "]" << std::endl;

        TokenProxy proxy(token);
        return proxy;
    };

    // ----- OPERATOR MAGIC

    // ----- OPERATOR MAGIC END

    void /* what exactly must be returned here ? */ build() {
        return;
    };
private:
    std::list<std::shared_ptr<Token>> tokens;
    ProductionMap productions;

    bool hasTokenType(const std::string& tokenType) {
        for(std::shared_ptr<Token>& t : this->tokens) {
            if(t->getType().compare(tokenType) == 0) return true;
        }

        return false;
    };

    std::shared_ptr<Token> createToken(const std::string& tokenType) {
        std::shared_ptr<Token> tmpToken(new Token(tokenType, ""));

        this->tokens.push_back(tmpToken);

        return tmpToken;
    };

    std::shared_ptr<Token> lookupToken(const std::string& tokenType) {
        for(std::shared_ptr<Token>& t : this->tokens) {
            if(t->getType().compare(tokenType) == 0) return t;
        }
        return std::shared_ptr<Token>(new Token("ERROR", "LOOKUP_ERROR"));
    };
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

ProductionRules getGoGrammar(std::list<std::shared_ptr<Token>>& terminalTokens) {
    ProductionRules grammar;

    //ProductionManager c(terminalTokens);
    // c->def("PackageClause") /*TokenProxy*/ = "package" + "PackageName" + '.';
    //c->def("SourceFile") = "PackageClause" + ';' + { "ImportDecl" + ';' } + { "TopLevelDecl" + ';' } + '.';
    //return c->build();
    

    return grammar;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////////  NEW APPORACH  ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// SourceFile       = PackageClause ";" { ImportDecl ";" } { TopLevelDecl ";" } .

// PackageClause  = "package" PackageName .
// PackageName    = identifier .

// ImportDecl       = "import" ( ImportSpec | "(" { ImportSpec ";" } ")" ) .
// ImportSpec       = [ "." | PackageName ] ImportPath .
// ImportPath       = string_lit .

// TopLevelDecl  = Declaration | FunctionDecl | MethodDecl .
// Declaration   = ConstDecl | TypeDecl | VarDecl .

// FunctionDecl = "func" FunctionName ( Function | Signature ) .
// FunctionName = identifier .
// Function     = Signature FunctionBody .
// FunctionBody = Block .

// MethodDecl   = "func" Receiver MethodName ( Function | Signature ) .
// Receiver     = Parameters .

// ConstDecl      = "const" ( ConstSpec | "(" { ConstSpec ";" } ")" ) .
// ConstSpec      = IdentifierList [ [ Type ] "=" ExpressionList ] .
//
// IdentifierList = identifier { "," identifier } .
// ExpressionList = Expression { "," Expression } .

// TypeDecl     = "type" ( TypeSpec | "(" { TypeSpec ";" } ")" ) .
// TypeSpec     = identifier Type .

// VarDecl     = "var" ( VarSpec | "(" { VarSpec ";" } ")" ) .
// VarSpec     = IdentifierList ( Type [ "=" ExpressionList ] | "=" ExpressionList ) .

}

#endif//GO_GRAMMAR_
