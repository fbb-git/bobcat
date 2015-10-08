#include "sharedpos.ih"

void SharedPos::update()
{
    bool beyondMax = d_offset > d_maxOffset;

    streamsize offset;
    if (beyondMax)
    {
        offset = d_offset;
        d_offset = d_maxOffset;
    }

    size_t segSize = segmentSize();

    d_blockIdx = d_offset / segSize;
    d_blockOffset = d_offset % segSize;

    if (beyondMax)
        throw Exception() << "Offset (" << offset << 
                            ") exceeds maxOffset (" << d_maxOffset << ')';
}
