#include "process.ih"

unsigned Process::whichStream()
{
    d_selector.wait();
    switch (unsigned count = d_selector.nReady())
    {
        case 0:
        return 0;

        case 1:
        return d_selector.getReadFd() == d_child_outp->getReadFd() ?
                    1
                :
                    2;
        case 2:
        return 3;

        default:
            throw Errno("Process::whichStream(): internal error. "
                "d_selector.nReady() returns ") << insertable <<
                count << ", should be <= 2" << throwable;
    }
}
