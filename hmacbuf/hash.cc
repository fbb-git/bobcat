#include "hmacbuf.hh"

string const &HMacBuf::hash() const
{
    return d_pimpl->digest;
}
