#include "extractorfork.ih"

void ExtractorFork::parentRedirections()
{
    int fd = d_iChildOutPipe.readOnly();

    d_iChildOutbuf.open(fd, 100);
    d_iChildOut.rdbuf(&d_iChildOutbuf);
}
