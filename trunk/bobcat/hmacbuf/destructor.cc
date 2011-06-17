#include "hmacbuf.ih"

HMacBuf::~HMacBuf()
{
    delete d_pimpl;
}
