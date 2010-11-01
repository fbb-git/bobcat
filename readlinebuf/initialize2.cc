#include "readlinebuf.ih"

ReadLineBuf &ReadLineBuf::initialize(std::string const &prompt, 
                                     size_t historySize, Type type)
{
    if (s_readLineBuf != 0)
        throw logic_error("ReadLineBuf already initialized");

    s_readLineBuf.reset(new ReadLineBuf(prompt, historySize, type));

    return *s_readLineBuf;
}
