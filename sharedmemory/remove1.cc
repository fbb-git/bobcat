#include "sharedmemory.hh"

void SharedMemory::remove()
{
    validate();

    lockAll();
    kill();
}
