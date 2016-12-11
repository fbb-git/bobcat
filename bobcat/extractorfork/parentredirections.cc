#include "extractorfork.ih"

void ExtractorFork::parentRedirections()
{
    open(d_iChildOutPipe.readOnly(), IFdStreambuf::CLOSE_FD, d_bufSize);
}
