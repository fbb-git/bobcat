#include "hmacbuf.ih"

HMacBufImp::HMacBufImp(std::string const &key, size_t bufsize)
:
    buffer(0),
    bufsize(bufsize),
    key(key)
{}
