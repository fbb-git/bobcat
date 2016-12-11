#include "extractorfork.ih"

void ExtractorFork::parentRedirections()
{
    open(d_iChildOutPipe.readOnly(), d_bufSize);
}
