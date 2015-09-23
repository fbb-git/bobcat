#include "sharedsegment.hh"

void SharedSegment::updateNreadable(streamsize offset)
{
    d_nReadableMutex.lock();
        if (offset > d_nReadable)
            d_nReadable = offset;
    d_nReadableMutex.unlock();
}
