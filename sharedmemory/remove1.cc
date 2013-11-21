#include "sharedmemory.ih"

void SharedMemory::remove()
{
    lockAll();
    kill();
}
