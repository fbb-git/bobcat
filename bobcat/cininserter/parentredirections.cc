#include "cininserter.ih"

void CinInserter::parentRedirections()
{
    open(d_oChildInPipe.writeOnly(), OFdStreambuf::CLOSE_FD, d_bufSize);
//    open(d_oChildInPipe.writeOnly(), d_bufSize);
}
