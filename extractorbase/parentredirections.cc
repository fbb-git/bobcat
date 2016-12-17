#include "extractorbase.ih"

void ExtractorBase::parentRedirections()
{
    open(d_iChildOutPipe.readOnly(), IFdStreambuf::CLOSE_FD, d_bufSize);
}
