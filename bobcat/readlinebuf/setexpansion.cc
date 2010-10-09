#include "readlinebuf.ih"

bool ReadLineBuf::setExpansion(HistoryExpansion::Type type)
{
    if (!d_history)
        return false;
    
    d_expansion = Expansion::ERROR;
    d_readline(type == NO_EXPANSION ? 
                       &ReadLineBuf::readLine : &ReadLineBuf::expandLine);
    return true;
}
