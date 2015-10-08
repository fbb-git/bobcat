#include "sharedmemory.ih"

bool SharedMemory::blockAvailable(size_t idx)
{
    if (d_data == 0)                        // no data available
        return false;

    if (d_pos.blockIdx() == idx)            // already loaded: done
        return true;

    d_sharedSegment->unlock(d_pos.blockIdx());  // clear an existing lock
    d_lockCount = 0;

    d_data = SharedSegment::detach(d_data);

    return false;
}
