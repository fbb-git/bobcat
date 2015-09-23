#include "sharedstreambuf.hh"

int SharedStreambuf::underflow()
{
    static char buf;

    int ret = mode(ios::in) ? d_memory.get() : EOF;

    if (ret != EOF)
    {
        buf = ret;
        setg(&buf, &buf, &buf + 1);
    }

    return ret;
}
