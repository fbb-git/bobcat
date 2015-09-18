#include "symcryptstreambufbase.hh"

#include <iostream>

bool SymCryptStreambufBase::filter(char const **srcBegin, char const **srcEnd)
{
    if (d_allDone)
        return false;

    d_in.read(d_inBuf.get(), d_inBufSize);

    size_t inBufRead = d_in.gcount();       // we got this many

    checkOutBufSize(inBufRead);
    
    int outBufSize;

    (*d_evpUpdate)(
            &d_ctx, 
            reinterpret_cast<unsigned char *>(d_outBuf.get()), &outBufSize, 
            reinterpret_cast<unsigned char *>(d_inBuf.get()), inBufRead
        );

    if (outBufSize == 0)
    {                                       // encryption
        checkOutBufSize(d_blockSize);
        (*d_evpFinal_ex)(
            &d_ctx, 
            reinterpret_cast<unsigned char *>(d_outBuf.get()), &outBufSize
        );
        d_allDone = true;
    }

    *srcBegin = d_outBuf.get();
    *srcEnd = *srcBegin + outBufSize;

    return outBufSize;
}

