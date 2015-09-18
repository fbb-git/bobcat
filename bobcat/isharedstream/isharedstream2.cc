#include "isharedstream.hh"

ISharedStream::ISharedStream(
                size_t maxSize, SharedMemory::SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
:
    SharedStreambuf(maxSize, sizeUnit, openMode, access),
    istream(this)
{}

 
