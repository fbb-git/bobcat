#include "sharedstreambuf.ih"

ios::pos_type SharedStreambuf::seekoff(
        ios::off_type   offset, 
        ios::seekdir    way, 
        ios::openmode   mode)
{
    offset = d_memory.seek(offset, way);

    if (offset != -1)
        d_currentMode = mode;

    return offset;
}
