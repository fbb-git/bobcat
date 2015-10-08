#include "digestbuf.ih"

DigestBuf::~DigestBuf()
{
    delete d_pimpl;
}
