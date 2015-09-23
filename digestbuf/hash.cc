#include "digestbuf.hh"

string const &DigestBuf::hash() const
{
    return d_pimpl->digest;
}

