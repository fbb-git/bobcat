#include "hmacbuf.hh"

HMacBuf::~HMacBuf()
{
    delete d_pimpl;
}
