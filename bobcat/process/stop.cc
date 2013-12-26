#include "process.ih"

int Process::stop()
{
    if (!d_active)
        return -1;

    d_oChildIn.flush();

    d_oChildInbuf.open(-1);
    d_iChildOutbuf.open(-1);
    d_iChildErrbuf.open(-1);

    closeWriteFd(d_oChildInPipe);
    closeReadFd(d_iChildOutPipe);
    closeReadFd(d_iChildErrPipe);

    discontinue(d_child);

    d_active = false;

    return d_child.ret;
}







