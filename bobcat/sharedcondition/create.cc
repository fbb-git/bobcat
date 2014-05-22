#include "sharedcondition.ih"

SharedCondition &SharedCondition::create(SharedMemory &shmem)
{
    void *ptr = shmem.ptr();

    if (ptr == 0 || shmem.seek(sizeof(SharedCondition) - 1) == -1)
        throw Exception() << "SharedCondition::create: out of memory.";
    
    shmem.put(0);

    return *new (ptr) SharedCondition();
}
