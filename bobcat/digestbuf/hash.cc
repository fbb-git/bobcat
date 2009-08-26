#include "digestbuf.ih"

string const &DigestBuf::hash() const
{
    return d_pimpl->digest;
}

