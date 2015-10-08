#include "sharedmemory.ih"

void SharedMemory::remove()
{
    validate();

    lockAll();
    kill();
}
