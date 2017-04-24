#ifndef COMPILER_REGEX_TOKEN_DEFINITION_
#define COMPILER_REGEX_TOKEN_DEFINITION_

#include <memory>
#include <regex>
#include <string>

#include "TokenDefinition.hxx"
#include "Token.hxx"

namespace anticom {

/**
 * Defines a token type via regex
 */
class RegexTokenDefinition : public TokenDefinition {
public:
    RegexTokenDefinition(const std::string& id, std::regex matcher);
    virtual ~RegexTokenDefinition();

    // ----- INTERFACE
    const std::string& getId() const override;
    bool matches(std::string& string) override;

    std::shared_ptr<Token> digest(std::string& string) override;
private:
    const std::string id;
    std::regex matcher;
};

// utility
//std::string regex_error_string(std::regex_constants::error_type error_type) {
    //switch(error_type) {
        //case std::regex_constants::error_collate: return "error_collate";
        //case std::regex_constants::error_ctype: return "error_ctype";
        //case std::regex_constants::error_escape: return "error_escape";
        //case std::regex_constants::error_backref: return "error_backref";
        //case std::regex_constants::error_brack: return "error_brack";
        //case std::regex_constants::error_paren: return "error_paren";
        //case std::regex_constants::error_brace: return "error_brace";
        //case std::regex_constants::error_badbrace: return "error_badbrace";
        //case std::regex_constants::error_range: return "error_range";
        //case std::regex_constants::error_space: return "error_space";
        //case std::regex_constants::error_badrepeat: return "error_badrepeat";
        //case std::regex_constants::error_complexity: return "error_complexity";
        //case std::regex_constants::error_stack: return "error_stack";
        //default: return "SHOULD_NEVER_HAPPEN!";
    //};
//};

}

#endif//COMPILER_REGEX_TOKEN_DEFINITION_
