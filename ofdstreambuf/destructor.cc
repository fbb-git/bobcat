#include "ofdstreambuf.hh"

OFdStreambuf::~OFdStreambuf()
{
    cleanup(d_mode);
}

