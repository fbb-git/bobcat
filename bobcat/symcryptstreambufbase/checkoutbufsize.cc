#include "symcryptstreambufbase.hh"

void SymCryptStreambufBase::checkOutBufSize(size_t inputSize)
{
    size_t outBufSize = (inputSize + d_blockSize - 1) / d_blockSize *
                                                                d_blockSize;

    if (outBufSize > d_outBufSize)
        d_outBuf.reset(new char[d_outBufSize = outBufSize]);
}
