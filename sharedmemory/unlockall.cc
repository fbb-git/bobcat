#include "sharedmemory.ih"

void SharedMemory::unlockAll()
{
    for (
        size_t idx = 0, end = d_sharedSegment->nBlocks();
            idx != end;
                ++idx
    )
        unlock(idx);

//cerr << "UNlocking shared segment\n";    
    d_sharedSegment->nReadableUnlock();
//cerr << "UNlockAll done\n";    
}
