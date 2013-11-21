#include "sharedmemory.ih"

ios::pos_type SharedMemory::seek(ios::off_type offset, ios::seekdir way)
{
    return d_pos.seek(offset, way);
}

