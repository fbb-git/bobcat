#include "encryptbuf.ih"

EncryptBufImp::EncryptBufImp(ostream &outStream, string const &ivv, 
                             size_t bufsize)
:
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

        for_each(iv.begin(), iv.end(), 
            FnWrap1c<char &, IRandStream &>(setChar, irs));
    }
}
