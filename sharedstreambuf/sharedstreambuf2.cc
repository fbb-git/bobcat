#include "sharedstreambuf.ih"

SharedStreambuf::SharedStreambuf(
                size_t maxSize, SharedMemory::SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
:
    d_openMode(openMode),
    d_currentMode(openMode & (ios::in | ios::out)),
    d_memory(maxSize, sizeUnit, access)
{
    setg(0, 0, 0);
    setp(0, 0);
}
