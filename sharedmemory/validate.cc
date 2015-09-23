#include "sharedmemory.hh"

void SharedMemory::validate() const
{
    if (d_sharedSegment == 0)
        throw Exception() << "SharedMemory not available";
}
