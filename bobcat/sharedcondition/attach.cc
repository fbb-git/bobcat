#include "sharedcondition.ih"

SharedCondition &SharedCondition::attach(SharedMemory &shmem,
                                            std::ios::off_type offset,
                                            std::ios::seekdir way)
{
    streamsize pos = shmem.seek(offset, way);

    verify(pos, "attach");

    return *reinterpret_cast<SharedCondition *>(shmem.ptr());
}
