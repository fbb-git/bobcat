#include "sharedpos.hh"

void SharedPos::reset(SharedSegment *sharedData)
{
    d_sharedData = sharedData;

    d_offset = 0;
    d_blockOffset = 0;
    d_maxOffset = static_cast<streamsize>(sharedData->nBlocks())
                                                            * segmentSize();
}
