#include "sharedmemory.hh"

    // unchecked: d_lockCount should be 0

void SharedMemory::lockAll()
{
    for (
        size_t idx = 0, end = d_sharedSegment->nBlocks();
            idx != end;
                ++idx
    )
        lock(idx);

//cerr << "locking shared segment\n";    
    d_sharedSegment->nReadableLock();
//cerr << "lockAll done\n";    
}
