#include "sharedmemory.ih"

void SharedMemory::clearAll()
{
    d_pos.reset(d_sharedSegment);
    d_lockCount = 0;
    d_data = SharedSegment::detach(d_data);

    d_sharedSegment->clear();
}
