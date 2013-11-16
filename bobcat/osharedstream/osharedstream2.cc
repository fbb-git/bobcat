#include "osharedstream.ih"

OSharedStream::OSharedStream(
                size_t maxSize, SharedMemory::SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
:
    SharedStreambuf(maxSize, sizeUnit, openMode, access),
    std::ostream(this)
{}

 
