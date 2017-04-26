
#include "AstPrinter.hxx"

TEST(AstPrinterTest, HandlesSimpleAst) {
    std::shared_ptr<TokenNode> ast;

    ast.push_back(
        std::shared_ptr<TokenNode>(new TokenNode(
            std::shared_ptr<Token>(new Token("TYPE_1", "VALUE_1"));
        ))
    );
    ast.push_back(
        std::shared_ptr<TokenNode>(new TokenNode(
            std::shared_ptr<Token>(new Token("TYPE_2", "VALUE_2"));
        ))
    );

    std::string expected = "";

    testing::internal::CaptureStdout();
    AstPrinter::print(ast);
    std::string actual = testing::internal::GetCapturedStdout();

    ASSERT_EQ(expected, actual);
}