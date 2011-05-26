#include "hmacbuf.ih"

string const &HMacBuf::hash() const
{
    return d_pimpl->digest;
}
