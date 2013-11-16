#include "sharedstream.ih"

void SharedStream::open(int id, std::ios::openmode openMode)
{
    setMemory(SharedMemory(id));
    setOpenMode(openMode);
    clear();
}

