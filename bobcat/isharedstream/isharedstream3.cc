#include "isharedstream.hh"

ISharedStream::ISharedStream(size_t id, std::ios::openmode openMode)
:
    SharedStreambuf(id, openMode),
    istream(this)
{}

