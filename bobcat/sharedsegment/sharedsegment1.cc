#include "sharedsegment.hh"

SharedSegment::SharedSegment(size_t access, size_t nBlocks, size_t segmentSize)
:
    d_access(access),
    d_segmentSize(segmentSize),
    d_nReadable(0),
    d_nBlocks(nBlocks)
{
                        // initialize the data-table. d_block[0] already has
                        // been initialized as `SharedBlock d_block[1]'
    for (
        SharedBlock *begin = d_block + 1, *end = d_block + d_nBlocks;
            begin != end;
                ++begin
    )
        new (begin) SharedBlock; 
}
