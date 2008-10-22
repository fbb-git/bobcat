#include "process.ih"

void Process::close()
{
    ::close(d_child_inp->writeFd());

    d_child_inp.reset(newPipe());
    d_child_inp->writeOnly();
}
