#include "sharedmemory.hh"

void SharedMemory::lock(size_t idx)
{
//cerr << "locking " << idx << ": " << d_lockCount << '\n';

    if (d_lockCount == 0)
        d_sharedSegment->lock(idx);

    ++d_lockCount;
}

