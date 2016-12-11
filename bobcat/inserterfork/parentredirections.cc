#include "inserterfork.ih"

void InserterFork::parentRedirections()
{
    open(d_oChildInPipe.writeOnly(), OFdStreambuf::CLOSE_FD, d_bufSize);
}
