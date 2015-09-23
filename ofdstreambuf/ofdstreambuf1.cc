#include "ofdstreambuf.hh"

OFdStreambuf::OFdStreambuf()
:
    d_mode(CLOSE_FD),          // comply with old default
    d_n(0),
    d_fd(-1),
    d_buffer(0)
{}

