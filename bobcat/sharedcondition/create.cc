#include "sharedcondition.ih"

SharedCondition SharedCondition::create(SharedMemory &shmem)
{
    size_t size = shmem.dataSegmentSize();
    if (size == 0)
        throw Exception() << 
            "SharedCondition::create: no memory at SharedMemory segment";


                        // find a suitable offset for the shared memory object
    size_t begin = shmem.blockOffset();
    size_t end = (begin + sizeof(Condition)) % size;
    if (begin + sizeof(Condition) != end)
        shmem.seek((1 + shmem.offset() / size) * size, ios::beg);

                                // determine the object's offset and address
    std::streamsize offset = shmem.offset();
    void *address = shmem.ptr();

                                            // go to the object's last byte
    if (address == 0 || shmem.seek(sizeof(Condition) - 1) == -1)
        throw Exception() << "SharedCondition::create: out of memory.";
    
            // make sure shmem knows it exists, and install the object at 
            // 'address'
    shmem.put(0);
    new (address) Condition();

            // return the SharedCondition object, which knows about the shared
            // memory and the Condition's offset
    return SharedCondition(shmem, offset);
}




