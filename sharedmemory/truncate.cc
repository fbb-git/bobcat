#include "sharedmemory.ih"

bool SharedMemory::truncate(streamsize offs)
{
    validate();

    bool ok = d_sharedSegment->truncate(offs);
    
    if (ok && offs < offset())
        d_pos.seek(offs);

    return ok;
}
