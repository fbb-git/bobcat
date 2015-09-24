#include "ifdstreambuf.ih"

IFdStreambuf::IFdStreambuf(Mode mode)
:
    d_mode(mode),
    d_fd(-1),
    d_n(0),
    d_buffer(0)
{}
