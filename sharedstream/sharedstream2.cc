#include "sharedstream.ih"

SharedStream::SharedStream(
                size_t maxSize, SharedMemory::SizeUnit sizeUnit,
                std::ios::openmode openMode, size_t access)
:
    SharedStreambuf(maxSize, sizeUnit, openMode, access),
    std::istream(this),
    std::ostream(this)
{}

