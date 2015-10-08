#include "sharedsegment.ih"

SharedSegment *SharedSegment::create(int *id, 
                                     size_t nBlocks, size_t segmentSize, 
                                     size_t access)
{
    *id = newSegment(segmentSize, access);

    SharedSegment *segmentPtr = static_cast<SharedSegment *>(attach(*id));

    new (segmentPtr) SharedSegment(access, nBlocks, segmentSize);

    return segmentPtr;
}
