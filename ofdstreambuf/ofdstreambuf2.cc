#include "ofdstreambuf.hh"

OFdStreambuf::OFdStreambuf(Mode mode)
:
    d_mode(mode),
    d_n(0),
    d_fd(-1),
    d_buffer(0)
{}

