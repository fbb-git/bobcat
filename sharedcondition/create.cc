#include "sharedcondition.hh"

SharedCondition SharedCondition::create(SharedMemory &shmem)
{
    std::streamsize offset;
    shmem.install<Condition>(&offset);

            // return the SharedCondition object, which knows about the shared
            // memory and the Condition's offset
    return SharedCondition(shmem, offset);
}








