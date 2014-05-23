#include "sharedcondition.ih"

void SharedCondition::verify(SharedMemory const &shmem, streamsize pos, 
                             char const *function)
{
    if (
        pos == -1 || 
        (
            static_cast<streamsize>(pos + sizeof(SharedCondition)) 
            >= 
            shmem.maxOffset()
        )
    )
        throw Exception() << "SharedCondition::" << 
                             function << ": invalid location.";
}
