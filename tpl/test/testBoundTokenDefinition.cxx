
#include <memory>
#include <sstream>

#include "gtest/gtest.h"

#include "BoundTokenDefinition.hxx"

using anticom::Token;
using anticom::BoundTokenDefinition;

TEST(BoundTokenDefinitionTest, MatchSingleLineTokenInSingleLineConfiguration) {
    BoundTokenDefinition td("TOKEN", "(", ")", false);

    std::string testcase = "(FIRST_WORD SECOND_WORD)";

    ASSERT_TRUE(td.matches(testcase));
}

TEST(BoundTokenDefinitionTest, MatchMultiLineTokenInMultilineConfiguration) {
    BoundTokenDefinition td("TOKEN", "(", ")", true);

    std::stringstream ss;
    ss << "(FIRST_LINE" << std::endl;
    ss << "SECOND_LINE)" << std::endl;
    std::string testcase = ss.str();

    ASSERT_TRUE(td.matches(testcase));
}

TEST(BoundTokenDefinitionTest, NotMatchMultiLineTokenInSingleLineConfiguration) {
    BoundTokenDefinition td("TOKEN", "(", ")", false);

    std::stringstream ss;
    ss << "(FIRST_LINE" << std::endl;
    ss << "SECOND_LINE)" << std::endl;
    std::string testcase = ss.str();

    ASSERT_FALSE(td.matches(testcase));
}

TEST(BoundTokenDefinitionTest, MatchSingleLineTokenInMultiLineConfiguration) {
    BoundTokenDefinition td("TOKEN", "(", ")", true);

    std::string testcase = "(FIRST_WORD SECOND_WORD)";

    ASSERT_TRUE(td.matches(testcase));
}

TEST(BoundTokenDefinitionTest, NotMatchTokenNotStartingWithLeftBoundary) {
    BoundTokenDefinition td("TOKEN", "(", ")", false);

    std::string testcase = "FIRST_WORD( SECOND_WORD)";

    ASSERT_FALSE(td.matches(testcase));
    
}

TEST(BoundTokenDefinitionTest, NotMatchTokenStartingWithRightBoundary) {
    BoundTokenDefinition td("TOKEN", "(", ")", false);

    std::string testcase = ")FIRST_WORD( SECOND_WORD)";

    ASSERT_FALSE(td.matches(testcase));
}

///////////////////////////////////////////////////////////////////////////////

TEST(BoundTokenDefinitionTest, ExtractSingleLineTokenCorreclty) {
    BoundTokenDefinition td("TOKEN", "(", ")", false);

    std::string testcase = "(FIRST_WORD SECOND_WORD)";

    ASSERT_EQ("FIRST_WORD SECOND_WORD", td.digest(testcase)->getValue());
}

TEST(BoundTokenDefinitionTest, ExtractMultiLineTokenCorreclty) {
    BoundTokenDefinition td("TOKEN", "(", ")", true);

    std::stringstream ss;
    ss << "(FIRST_LINE" << std::endl;
    ss << "SECOND_LINE)" << std::endl;
    std::string testcase = ss.str();

    std::stringstream ssExpected;
    ssExpected << "FIRST_LINE" << std::endl;
    ssExpected << "SECOND_LINE";

    ASSERT_EQ(ssExpected.str(), td.digest(testcase)->getValue());
}
