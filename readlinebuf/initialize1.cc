#include "readlinebuf.hh"

ReadLineBuf &ReadLineBuf::initialize(std::string const &prompt, Type type)
{
    if (s_readLineBuf.get() != 0)
        throw logic_error("ReadLineBuf already initialized");

    s_readLineBuf.reset(new ReadLineBuf(prompt, type));

    return *s_readLineBuf;
}
