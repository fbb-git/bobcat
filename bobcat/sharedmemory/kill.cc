#include "sharedmemory.ih"

void SharedMemory::kill()
{
    clearAll();
    d_sharedSegment->deleteSegment(d_id);
    d_sharedSegment = SharedSegment::detach(d_sharedSegment);
}
