#include "decryptbuf.ih"

DecryptBufImp::DecryptBufImp(ostream &outStream, size_t bufsize)
:
    ctx(EVP_CIPHER_CTX_new()),
    active(false),
    bufsize(bufsize),
    buffer(0),
    out(0),
    outStream(outStream)
{}
