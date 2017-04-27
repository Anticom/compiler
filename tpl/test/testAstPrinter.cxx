
#include <sstream>

#include "gtest/gtest.h"

#include "AstPrinter.hxx"

using anticom::Token;
using anticom::TokenNode;
using anticom::AstPrinter;

TEST(AstPrinterTest, HandlesSimpleAst) {
    std::shared_ptr<TokenNode> ast = std::shared_ptr<TokenNode>(new TokenNode(
        std::shared_ptr<Token>(new Token("ROOT", "ROOT"))
    ));

    ast->addChild(
        std::shared_ptr<Token>(new Token("TYPE_1", "VALUE_1"))
    );
    ast->addChild(
        std::shared_ptr<Token>(new Token("TYPE_2", "VALUE_2"))
    );

    // assuming default indentation of 2
    std::stringstream ss;
    ss << "[ROOT : ROOT]" << std::endl;
    ss << "  [TYPE_1 : VALUE_1]" << std::endl;
    ss << "  [TYPE_2 : VALUE_2]" << std::endl;
    std::string expected = ss.str();

    testing::internal::CaptureStdout();
    AstPrinter::print(ast);
    std::string actual = testing::internal::GetCapturedStdout();

    ASSERT_EQ(expected, actual);
}
