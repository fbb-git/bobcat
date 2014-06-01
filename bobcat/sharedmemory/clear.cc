#include "sharedmemory.ih"

void SharedMemory::clear()
{
    validate();
    lockAll();
    clearAll();
    unlockAll();
}
