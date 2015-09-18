#include "sharedmemory.hh"

    // private, only called by load.

void SharedMemory::map(size_t idx)
{
    int id = (*d_sharedSegment)[idx].id();

    bool newData = id == -1;

    if (newData)
    {
       d_sharedSegment->lock(idx);
       id = d_sharedSegment->newData(idx);
    }

    d_data = static_cast<char *>(SharedSegment::attach(id));

    if (newData)
    {
        memset(d_data, 0, d_sharedSegment->size(id));
        d_sharedSegment->unlock(idx);
    }
}
