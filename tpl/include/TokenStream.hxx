#ifndef COMPILER_TOKEN_STREAM_
#define COMPILER_TOKEN_STREAM_

#include <memory>
#include <list>

#include "Token.hxx"

namespace anticom {

class TokenStream : public std::list<std::shared_ptr<Token>> {};

}

#endif//COMPILER_TOKEN_STREAM_
