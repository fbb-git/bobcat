#include "readlinebuf.hh"

ReadLineBuf &ReadLineBuf::instance()
{
    if (s_readLineBuf.get() == 0)
        throw logic_error("ReadLineBuf not yet initialized");

    return *s_readLineBuf;
}
