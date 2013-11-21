#include "sharedmemory.ih"

int SharedMemory::put(int ch)
{
    char *cp = ptr();           // ptr() loads the proper data segment

    if (cp == 0)
        return EOF;

    lock(d_pos.blockIdx());
        *cp = ch;
        ++d_pos;
    unlock(d_pos.blockIdx());
    d_sharedSegment->updateNreadable(d_pos.offset());

    return ch;
}


