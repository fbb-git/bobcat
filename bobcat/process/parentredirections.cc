#include "process.hh"

void Process::parentRedirections()
{
    d_selector = Selector();

    if (d_setMode & CLOSE_ON_EXEC)
        closeChildInputOnExec();

    if (d_mode & CIN)
    {
        int fd = d_oChildInPipe.writeOnly();

        if (not (d_setMode & IN_PIPE))
        {
            d_oChildInbuf.open(fd, 200);
            d_oChildIn.rdbuf(&d_oChildInbuf);
        }
    }

    if (d_mode & (COUT | MERGE_COUT_CERR))
    {
        int fd = d_iChildOutPipe.readOnly();

        if (not (d_setMode & OUT_PIPE))
        {
            d_iChildOutbuf.open(fd, 200);
            d_iChildOut.rdbuf(&d_iChildOutbuf);
            d_selector.addReadFd(fd);
        }
    }
    else
        closeWriteFd(d_iChildOutPipe);

    if (d_mode & CERR)
    {
        int fd = d_iChildErrPipe.readOnly();
        d_iChildErrbuf.open(fd, 200);
        d_iChildErr.rdbuf(&d_iChildErrbuf);
        d_selector.addReadFd(fd);
    }

    clear();                // clears IOStream's streams
}





