#include "process.ih"

void Process::setPipes(iomode mode)
{
//    d_mode = mode;

    d_oldIn =  d_child_inp.get()  ? d_child_inp->writeFd() : -1;
    d_oldOut = d_child_outp.get() ? d_child_outp->readFd() : -1;

    d_child_inp.reset(mode & CIN ? newPipe() : 0);
    d_child_outp.reset(mode & (COUT | MERGE_COUT_CERR) ? newPipe() : 0);

//    d_child_errp.reset(mode & CERR && !(mode & MERGE_COUT_CERR) ?
//                                                        newPipe() : 0);
}


