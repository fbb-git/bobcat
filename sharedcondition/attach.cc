#include "sharedcondition.ih"

SharedCondition SharedCondition::attach(SharedMemory &shmem,
                                            std::ios::off_type offset,
                                            std::ios::seekdir way)
{
    streamsize currentOffset = shmem.offset();

    SharedCondition ret(shmem, shmem.seek(offset, way));

    shmem.seek(currentOffset);

    return ret;
}
