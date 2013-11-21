#include "sharedmemory.ih"

SharedMemory::SharedMemory(size_t maxSize, SizeUnit sizeUnit, size_t access)
{
    size_t nBlocks;
    size_t segmentSize = computeSegmentSize(&nBlocks, maxSize, sizeUnit);

    d_sharedSegment = 
            SharedSegment::create(&d_id, nBlocks, segmentSize, access);

    d_pos.reset(d_sharedSegment);
}





