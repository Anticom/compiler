
////////////////////////////////////////////////////////////////////////////////
// NOTES:
// - Regex sucks: http://stackoverflow.com/a/21689738/966530
////////////////////////////////////////////////////////////////////////////////
// BUGS:
// - [DONE] interpreted string probably can't span multiple lines (?)
////////////////////////////////////////////////////////////////////////////////
// MAJOR TODOS:
// - find a way to add meta-data to tokens (filename, col, row) 
// - refactor getId impl to TokenDefinition interface
// - refactor slurping of token to lexer
//   --> not possible bc of lambdas :/
//   --> could return smatch and use smatch::str(0).length() maybe?
//   - implement TokenChoosingStrategy
//     - FirstComeFirstServerStrategy
//     - LongestTokenStrategy
//     - ShortestTokenStrategy
//   - get rid of TokenDefinition::matches
//     - get caching online for the TokenDefinitions
// - either remove id from LambdaDefinitionToken or somehow utilize it in callback(s)
// - improve File interface
// - PARSER
// - SYMBOL_TABLE
////////////////////////////////////////////////////////////////////////////////
// NICE TO HAVES:
// - implement custom wrapper arround char* which can be reduced from the front
// - Make Tokens reconstructable
////////////////////////////////////////////////////////////////////////////////

// C++ includes
#include <string>
#include <sstream>
#include <iostream>

#include <memory>

#include <list>
#include <unordered_map>

// C includes
#include <cstdint>
#include <cstdarg>

// Project includes
// ---- GENERAL
#include "File.hxx"
#include "Token.hxx"

// ----- LEXING
// will include all TokenDefinitions for us
#include "TokenDefinitionFactory.hxx"

// will include TokenStream for us aswell
#include "Lexer.hxx"

// ----- PARSING
#include "TokenNode.hxx"
#include "SymbolTable.hxx"

#include "ProductionRule.hxx"
#include "ProductionRules.hxx"
#include "ProductionRuleBuilder.hxx"

// will include all the basics you'll need (eventually...)
#include "Compiler.hxx"

// ----- DEV TOOLS
#include "TokenStreamPrinter.hxx"
#include "AstPrinter.hxx"

// ====== GO ======
#include "syntax.hxx"
#include "grammar.hxx"

namespace anticom {

class ExecutionPlan {
public:
    ExecutionPlan() {};
    virtual ~ExecutionPlan() {};

    // what is the actual return type; maybe a partial AST which will be attached to currend node?
    /*AST?*/ void execute() {
        
    };
private:
};

} // END OF NAMESPACE 'anticom'

using namespace anticom;

int main(int argc, char** argv) {
    //try {
        File file("./hello.go");

        //Compiler compiler = Compiler(Lexer(getGoSyntax()), Parser(getGoGrammar()));
        //std::shared_ptr<TokenNode> ast = compiler.compile(file);

        Lexer lexer(getGoSyntax());
        Parser parser(getGoGrammar());

        TokenStream ts = lexer.lex(file);
        TokenStreamPrinter::print(ts);

        std::cout << "----------" << std::endl;
        std::cout << "----------" << std::endl;
        std::cout << "----------" << std::endl;
        
        std::shared_ptr<TokenNode> ast = parser.parse(ts);
        AstPrinter::print(ast);
    /*
    } catch(const std::regex_error& e) {
        std::cerr << "Regex error!" << std::endl;
        std::cerr << e.code() << ": " << e.what() << ": " << regex_error_string(e.code()) << std::endl;
        return 1;
    } catch(const std::exception& e) {
        std::cerr << "Something went wrong!" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    */

    return 0;
};

