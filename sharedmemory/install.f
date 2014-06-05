template <typename SharedType, typename ... Params>
SharedType *SharedMemory::install(std::streamsize *offsetPtr, 
                                  Params &&...params)
{
    size_t segmentSize = dataSegmentSize();
    if (segmentSize == 0)
        throw Exception() << "SharedMemory::install: no memory";

                        // find a suitable offset for the shared memory object
    size_t begin = blockOffset();
    size_t end = (begin + sizeof(SharedType)) % segmentSize;
    if (begin + sizeof(SharedType) != end)
        seek((1 + offset() / segmentSize) * segmentSize);

                                // determine the object's offset and address
    std::streamsize location = offset();
    void *address = ptr();

                                            // go to the object's last byte
    if (address == 0 || seek(sizeof(SharedType) - 1) == -1)
        throw Exception() << "SharedMemory::install: out of memory.";
    
            // make sure shmem knows it exists by writing a byte at its last
            // byte location
    put(0);       

    if (offsetPtr)
        *offsetPtr = location;

            // install the object at 'address'
    return new (address) SharedType(std::forward<Params>(params)...);
}
