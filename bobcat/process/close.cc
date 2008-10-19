#include "process.ih"

void Process::close(auto_ptr<Pipe> &pipe)
{
    if (pipe.get())
    {
        ::close(pipe->writeFd());
        ::close(pipe->readFd());
        pipe.reset(0);
    }

}
