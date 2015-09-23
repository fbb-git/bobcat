#include "ifdstreambuf.hh"

IFdStreambuf::IFdStreambuf()
:
    d_mode(KEEP_FD),         // comply with old default
    d_fd(-1),
    d_n(0),
    d_buffer(0)
{}

