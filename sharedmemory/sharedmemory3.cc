#include "sharedmemory.hh"

SharedMemory::SharedMemory(int id)
:
    d_id(id),
    d_sharedSegment(static_cast<SharedSegment *>(SharedSegment::attach(id)))
{
    d_pos.reset(d_sharedSegment);
}
