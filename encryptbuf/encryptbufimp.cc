#include "encryptbuf.ih"

EncryptBufImp::EncryptBufImp(ostream &outStream, string const &ivv, 
                             size_t bufsize)
:
    ctx(EVP_CIPHER_CTX_new()),
    active(false),
    bufsize(bufsize),
    buffer(0),
    out(0),
    iv(ivv),
    outStream(outStream)
{
    if (iv.empty())
    {
        iv.resize(EVP_MAX_IV_LENGTH);

        IRandStream irs(0, 255, time(0));

        for (auto &ch: iv)
            setChar(ch, irs);
    }
}






