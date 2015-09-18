#include "sharedmemory.hh"

char *SharedMemory::ptr()
{
    if (d_pos.atMaxOffset())
        return 0;

    validate();
    map();                                      // map block[d_blockIdx]
    return d_data + d_pos.blockOffset();
}
