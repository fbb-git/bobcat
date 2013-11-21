#include "sharedsegment.ih"

int SharedSegment::newSegment(size_t requestedSize, size_t access)
{
    int id = shmget(IPC_PRIVATE, requestedSize, access);

    if (id == -1)                           // no block available
        throw Exception() << "Cannot create a shared segment segment";

    size_t actualSize = size(id);

    if (actualSize != requestedSize)
        throw Exception() << "Incorrect size (" << actualSize << 
                            ", should be: " << requestedSize << 
                            ") of shared segment";

    return id;
}
