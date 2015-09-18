#include "digestbuf.hh"

DigestBuf::~DigestBuf()
{
    delete d_pimpl;
}
