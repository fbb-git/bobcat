#include "sharedcondition.ih"

SharedCondition &SharedCondition::create(std::streamsize *pos, 
                                         SharedMemory &shmem)
{
    size_t size = shmem.dataSegmentSize();
    if (size == 0)
        throw Exception() << 
            "SharedCondition::create: no memory at SharedMemory segment";

    size_t begin = shmem.blockOffset();
    size_t end = (begin + sizeof(SharedCondition)) % size;

    if (begin + sizeof(SharedCondition) != end)
        shmem.seek((1 + shmem.offset() / size) * size, ios::beg);

    *pos = shmem.offset();
    void *ptr = shmem.ptr();

    if (ptr == 0 || shmem.seek(sizeof(SharedCondition) - 1) == -1)
        throw Exception() << "SharedCondition::create: out of memory.";
    
    shmem.put(0);

    return *new (ptr) SharedCondition();
}




