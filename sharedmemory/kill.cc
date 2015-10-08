#include "sharedmemory.ih"

void SharedMemory::kill()
{
    if (d_id == -1)
        return;

    clearAll();
    d_sharedSegment->deleteSegment(d_id);
    d_sharedSegment = SharedSegment::detach(d_sharedSegment);
    d_id = -1;
}
