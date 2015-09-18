#include "sharedmemory.hh"

void SharedMemory::unlock(size_t idx)
{
//cerr << "UNlocking " << idx << ": " << d_lockCount << '\n';

    if (d_lockCount && --d_lockCount == 0)
        d_sharedSegment->unlock(idx);
}

