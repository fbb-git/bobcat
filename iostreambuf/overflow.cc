#include "iostreambuf.hh"

int IOStreambuf::overflow(int c)
{
    if (c == EOF)
        d_out->flush();
    else
        d_out->put(c);
    return c;
}
