#include "ifilterstreambuf.ih"

int IFilterStreambuf::underflow()
{
    if (d_srcBegin == d_srcEnd)                 // no source bytes, then
    {                                           // get some. If none available
        if (not filter(&d_srcBegin, &d_srcEnd)) // return EOF
            return EOF;
    }

    size_t srcSize = d_srcEnd - d_srcBegin;     // #available source bytes

        // as long as all src bytes fit in the buffer they can all be stored
    if (srcSize <= d_remaining)
        src2buffer(srcSize);

        // else, if there is remaining space, use it to store some of the
        //       source bytes
    else if (d_remaining)
        src2buffer(d_remaining);

        // else, create some remaining space by removing initial bytes from
        //       the buffer, which therefore can no longer be ungot.
    else if (srcSize <= d_maxRefresh)
        makeAvailable(srcSize);

        // else load at most d_maxRefresh of the available source bytes
    else 
        makeAvailable(d_maxRefresh);

    setg(d_begin, d_next, d_end);       // reload the input buffer

    return *gptr();                     // return the next available char
}

