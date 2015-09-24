#include "isharedstream.ih"

ISharedStream::ISharedStream(size_t id, std::ios::openmode openMode)
:
    SharedStreambuf(id, openMode),
    istream(this)
{}

