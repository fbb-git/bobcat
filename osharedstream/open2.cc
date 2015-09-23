#include "osharedstream.hh"

void OSharedStream::open(int id, std::ios::openmode openMode)
{
    setMemory(SharedMemory(id));
    setOpenMode(openMode);
    clear();
}
