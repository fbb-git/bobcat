#include "readlinebuf.ih"

ReadLineBuf &ReadLineBuf::instance()
{
    if (s_readLineBuf == 0)
        throw logic_error("ReadLineBuf not yet initialized");

    return *s_readLineBuf;
}
