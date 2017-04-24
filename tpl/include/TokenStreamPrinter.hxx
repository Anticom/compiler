#ifndef COMPILER_TOKEN_STREAM_PRINTER_
#define COMPILER_TOKEN_STREAM_PRINTER_

#include "TokenStream.hxx"

namespace anticom {

/**
 * Pretty-prints the token stream to console
 * For debugging purposes etc.
 */
class TokenStreamPrinter {
public:
    TokenStreamPrinter() = delete;

    static void print(TokenStream ts);
    static void reconstruct(TokenStream ts);
};

}

#endif//COMPILER_TOKEN_STREAM_PRINTER_
