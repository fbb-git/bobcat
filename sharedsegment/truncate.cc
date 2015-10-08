#include "sharedsegment.ih"

bool SharedSegment::truncate(streamsize offset)
{
    if (offset < 0)
        return false;

    nReadableLock();

    bool ret = offset <= d_nReadable;
    if (ret)
        d_nReadable = offset;
    
    nReadableUnlock();

    return ret;
}
