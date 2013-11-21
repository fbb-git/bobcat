#include "sharedmemory.ih"

streamsize SharedMemory::showmanyc()
{
    return d_pos.eof() ? 0 : d_pos.showmanyc();
}

