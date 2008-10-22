#include "process.ih"

size_t Process::whichStream()
{
    d_selector.wait();

    switch (size_t count = d_selector.nReady())
    {
        case 0:
        return NOTHING_AVAILABLE;

        case 1:
        return d_selector.getReadFd() == d_child_outp->readFd() ? 
                    CHILD_OUTPUT 
                : 
                    CHILD_ERROR;
        case 2:
        return CHILD_OUTPUT | CHILD_ERROR;

        default:
            throw Errno("Process::whichStream(): internal error. "
                "d_selector.nReady() returns ") << insertable <<
                count << ", should be <= 2" << throwable;
    }
}
