#include "sharedmemory.hh"

SharedMemory::~SharedMemory()
{
    SharedSegment::detach(d_data, false);
    SharedSegment::detach(d_sharedSegment, false);
}
