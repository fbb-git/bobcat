#include "decryptbuf.ih"

DecryptBufImp::DecryptBufImp(ostream &outStream, size_t bufsize)
:
    active(false),
    bufsize(bufsize),
    buffer(0),
    out(0),
    outStream(outStream)
{}
