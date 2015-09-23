#include "main.hh"

void newPipes()
{
    oldIn =  d_child_inp.get()  ? d_child_inp->writeFd() : -1;
    oldOut = d_child_outp.get() ? d_child_outp->readFd() : -1;

    d_child_inp.reset(newPipe());
    d_child_outp.reset(newPipe());
}
