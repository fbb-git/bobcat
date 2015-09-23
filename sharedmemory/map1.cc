#include "sharedmemory.hh"

void SharedMemory::map()
{
    size_t idx = d_pos.blockIdx();          // block idx to use

//cerr << "map: using block " << idx << '\n';

    if (not blockAvailable(idx))
        map(idx);
}



