#include "readlinebuf.hh"

bool ReadLineBuf::useTimestamps(string (*timestamp)())
{
    if (!d_history)
        return false;

    d_timestamp = timestamp;
    return true;
}
