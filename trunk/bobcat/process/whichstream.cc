#include "process.ih"

size_t Process::whichStream()
{
    d_selector.wait();
    switch (size_t count = d_selector.nReady())
    {
        case 0:
        return 0;

        case 1:
        return d_selector.getReadFd() == d_child_outp->readFd() ?
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
