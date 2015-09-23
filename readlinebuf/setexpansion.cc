#include "readlinebuf.hh"

bool ReadLineBuf::setExpansion(Type type)
{
    if (!d_history)
        return false;
    
    d_expansion = ERROR;

    d_readline = 
        type == DONT_EXPAND_HISTORY ? 
                &ReadLineBuf::readLine : &ReadLineBuf::expandLine;

    return true;
}
