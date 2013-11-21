#include "sharedmemory.ih"

// Memory computation
//     P: standard page size
//     x: required multiplication for P to compute the blockSize
//     b: sizeof(Block): blockEntry
//     h: size of the header: sizeof(SharedSegment) - b
//     M: max available memory
// Each entry of SharedSegment::block points to xP bytes
// If there are n entries in block, then n*xP == M
// 
// The block array in the SharedSegment segment itself consists of xP - h bytes,
// holding (xP - h) / e entries. 
// 
// Therefore, (xP - h) / b * xP == M.
// 
//     ->  sqr(P) / b * sqr(x) - h P / b * x - M   = 0
//         --- a  ---          --- b ---     - c -
// 
// The quadratic equation is solved for x, which is rounded upward to compute
// the real maximum memory size.

size_t SharedMemory::computeSegmentSize(
                            size_t *nBlocks, 
                            long long maxMemory, SizeUnit sizeUnit)
{
    typedef SharedBlock Entry;

    maxMemory <<= sizeUnit;

    double a = static_cast<double>(PAGESIZE) * PAGESIZE / sizeof(Entry);
    
    double b = -static_cast<double>(sizeof(SharedSegment) - sizeof(Entry)) 
                * PAGESIZE / sizeof(Entry);

    double c = -maxMemory;
    
    size_t factor = static_cast<size_t>(       // size of allocated blocks
                        ceil((-b + sqrt(b * b - 4 * a * c)) / (2 * a))
                    );

    size_t segmentSize = factor * PAGESIZE;

    *nBlocks = (segmentSize - (sizeof(SharedSegment) - sizeof(Entry))) 
                    / sizeof(Entry);

    return segmentSize;
}
