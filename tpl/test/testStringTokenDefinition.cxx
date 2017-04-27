
#include <memory>
#include <list>
#include <sstream>
#include <string>

#include "gtest/gtest.h"

#include "StringTokenDefinition.hxx"

using anticom::Token;
using anticom::StringTokenDefinition;

TEST(StringTokenDefinitionTest, MatchTokenSeperatedByWhitespace) {
    StringTokenDefinition td("TOKEN", "FIRST_WORD");

    std::string testcase = "FIRST_WORD SECOND_WORD";

    ASSERT_TRUE(td.matches(testcase));
}

// TODO do we want this behaviour? Maybe we can add flag to request whitespace after token?
TEST(StringTokenDefinitionTest, MatchTokenNotSeperatedByWhitespace) {
    StringTokenDefinition td("TOKEN", "FIRST_WORD");

    std::string testcase = "FIRST_WORD SECOND_WORD";

    ASSERT_TRUE(td.matches(testcase));
}

TEST(StringTokenDefinitionTest, NotMatchToken) {
    StringTokenDefinition td("TOKEN", "FIRST_WORD");

    std::string testcase = "FIRST_WORD SECOND_WORD";

    ASSERT_TRUE(td.matches(testcase));
}

///////////////////////////////////////////////////////////////////////////////

TEST(StringTokenDefinitionTest, ExtractTokenCorreclty) {
    StringTokenDefinition td("TOKEN", "FIRST_WORD");

    std::list<std::pair<std::string, std::string>> pairsOfExpectedAndTestcase = {
        std::make_pair("FIRST_WORD", "FIRST_WORD SECOND_WORD"),
        std::make_pair("FIRST_WORD", "FIRST_WORDSECOND_WORD")
    };

    for(auto et : pairsOfExpectedAndTestcase) {
        std::string expected = et.first;
        std::string testcase = et.second;

        ASSERT_EQ(expected, td.digest(testcase)->getValue());
    }
}
