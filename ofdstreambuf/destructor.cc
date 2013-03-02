#include "ofdstreambuf.ih"

OFdStreambuf::~OFdStreambuf()
{
    cleanup(d_mode);
}

