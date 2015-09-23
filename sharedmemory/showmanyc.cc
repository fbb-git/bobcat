#include "sharedmemory.hh"

streamsize SharedMemory::showmanyc()
{
    return d_pos.eof() ? 0 : d_pos.showmanyc();
}

