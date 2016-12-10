#include "inserterfork.ih"

void InserterFork::parentRedirections()
{
    int fd = d_oChildInPipe.writeOnly();

    d_oChildInbuf.open(fd, FBB::OFdStreambuf::CLOSE_FD, 80);
    d_oChildIn.rdbuf(&d_oChildInbuf);
}
