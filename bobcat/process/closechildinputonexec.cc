#include "process.ih"

void Process::closeChildInputOnExec()
{
#ifdef BOBCAT_DIY_CLOEXEC_
    int writeDup[] =    
        {
            d_oChildInPipe.readFd(), 
            fcntl(d_oChildInPipe.writeOnly(), F_DUPFD, 4)
        };
    d_closedByChild = writeDup[1];
#else
    int writeDup[] =    
        {
            d_oChildInPipe.readFd(), 
            fcntl(d_oChildInPipe.writeOnly(), F_DUPFD_CLOEXEC, 4)
        };
#endif

    closeWriteFd(d_oChildInPipe);
                                    // OFdStreambuf set at parentRedirections
    d_oChildInPipe = Pipe(writeDup);
}



