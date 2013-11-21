#include "sharedmemory.ih"

void SharedMemory::clear()
{
    lockAll();
    clearAll();
    unlockAll();
}
