#include "sharedmemory.hh"

void SharedMemory::clear()
{
    validate();
    lockAll();
    clearAll();
    unlockAll();
}
