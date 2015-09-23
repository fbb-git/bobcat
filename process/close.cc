#include "process.hh"

void Process::close()
{
    d_oChildIn.flush();

    closeWriteFd(d_oChildInPipe);

    if (d_oChildIn.rdbuf() != 0)
        close(d_oChildInbuf.fd());

    d_oChildIn.rdbuf(0);     
}





