#include "process.ih"

size_t Process::whichStream()
{
    d_selector.wait();

    switch (size_t count = d_selector.nReady())
    {
        case 0:
        return NOTHING_AVAILABLE;

        case 1:
        return d_selector.readFd() == d_child_outp->readFd() ? 
                    CHILD_COUT 
                : 
                    CHILD_CERR;
        case 2:
        return CHILD_COUT | CHILD_CERR;

        default:
            throw Errno("Process::whichStream(): internal error. "
                                        "d_selector.nReady() returns ") << 
                         count << " (should be <= 2)";
    }
}
