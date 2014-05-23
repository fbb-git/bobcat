#include "sharedcondition.ih"

SharedCondition &SharedCondition::readAttach(SharedMemory &shmem,
                                            std::ios::off_type offset,
                                            std::ios::seekdir way)
{
    streamsize pos = shmem.seek(offset, way);
    shmem.read(reinterpret_cast<char *>(&pos), sizeof(pos));
    shmem.seek(pos, ios:beg);

    verify(
    if (pos == -1 || (
        static_cast<streamsize>(pos + sizeof(SharedCondition)) 
        >= shmem.maxOffset())
    )
        throw Exception() << "SharedCondition::attach: invalid location.";

    return *reinterpret_cast<SharedCondition *>(shmem.ptr());
}
