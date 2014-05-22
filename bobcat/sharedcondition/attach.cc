#include "sharedcondition.ih"

SharedCondition &SharedCondition::attach(SharedMemory &shmem,
                                            std::ios::off_type offset,
                                            std::ios::seekdir way)
{
    //std::ios::pos_type pos = shmem.seek(offset, way);
    std::streamsize pos = shmem.seek(offset, way);

    if (pos == -1 || (
        static_cast<streamsize>(pos + sizeof(SharedCondition)) 
        >= shmem.maxOffset())
    )
        throw Exception() << "SharedCondition::attach: invalid location.";

    return *reinterpret_cast<SharedCondition *>(shmem.ptr());
}
