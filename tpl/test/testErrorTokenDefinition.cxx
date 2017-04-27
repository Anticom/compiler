
#include <memory>
#include <list>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

#include "ErrorTokenDefinition.hxx"

using anticom::Token;
using anticom::ErrorTokenDefinition;

TEST(ErrorTokenDefinitionTest, AllwaysMatches) {
    ErrorTokenDefinition td;

    std::list<std::string> listOfTestcases{ "", " ", "FOO" };
    for(std::string testcase : listOfTestcases) {
        ASSERT_TRUE(td.matches(testcase));
    }
}

// Also produces ERROR token
TEST(ErrorTokenDefinitionTest, AllwaysDigestsUntillNextWhitespace) {
    ErrorTokenDefinition td;

    std::list<std::pair<std::string, std::string>> pairsOfExpectedAndTestcase = {
        std::make_pair( "FOO", "FOO" ),
        std::make_pair( "FOO", "FOO BAR" ),
        std::make_pair( ""   , " FOO" )
    };

    for(auto et : pairsOfExpectedAndTestcase) {
        std::string expected = et.first;
        std::string testcase = et.second;

        ASSERT_EQ(expected, td.digest(testcase)->getValue());
    }
}
