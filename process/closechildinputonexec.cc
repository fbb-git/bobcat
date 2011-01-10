#include "process.ih"

void Process::closeChildInputOnExec()
{
    int writeDup[] =    
        {
            d_oChildInPipe.readFd(), 
            fcntl(d_oChildInPipe.writeOnly(), F_DUPFD_CLOEXEC, 4)
        };

    closeWriteFd(d_oChildInPipe);
                                    // OFdStreambuf set at parentRedirections
    d_oChildInPipe = Pipe(writeDup);
}
