#include "osharedstream.hh"

OSharedStream::OSharedStream(size_t id, std::ios::openmode openMode)
:
    SharedStreambuf(id, openMode),
    std::ostream(this)
{}

