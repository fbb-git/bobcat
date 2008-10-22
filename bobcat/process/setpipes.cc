#include "process.ih"


void Process::setPipes()
{
    d_oldIn =  d_child_inp.get()  ? d_child_inp->writeFd() : -1;
    d_oldOut = d_child_outp.get() ? d_child_outp->readFd() : -1;
    d_oldErr = d_child_errp.get() ? d_child_errp->readFd() : -1;

    d_child_inp.reset(d_mode & CIN ? newPipe() : 0);
    d_child_outp.reset(d_mode & (COUT | MERGE_COUT_CERR) ? newPipe() : 0);
    d_child_errp.reset(d_mode & CERR ? newPipe() : 0);

    std::cerr << "setPipes, oldIn = " << d_oldIn << ", current FD " <<
    d_child_inp->writeFd() << "\n"; 
}


