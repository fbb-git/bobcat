#include "sharedcondition.ih"

SharedCondition &SharedCondition::readAttach(SharedMemory &shmem,
                                            std::ios::off_type offset,
                                            std::ios::seekdir way)
{
    streamsize pos = shmem.seek(offset, way);
    shmem.read(reinterpret_cast<char *>(&pos), sizeof(pos));
    pos = shmem.seek(pos, ios::beg);

    verify(shmem, pos, "readAttach");

    return *reinterpret_cast<SharedCondition *>(shmem.ptr());
}
