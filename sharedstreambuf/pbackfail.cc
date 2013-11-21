#include "sharedstreambuf.ih"

int SharedStreambuf::pbackfail(int ch)
{
    if (seekoff(-1) == -1)
        ch = EOF;
    else if (*d_memory.ptr() != ch)
    {
        seekoff(+1);  // undo the seek
        ch = EOF;
    }

    return ch;
}
