#include "isharedstream.ih"

void ISharedStream::open(int id, std::ios::openmode openMode)
{
    setMemory(SharedMemory(id));
    setOpenMode(openMode);
    clear();
}
