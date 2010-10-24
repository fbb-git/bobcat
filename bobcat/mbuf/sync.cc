#include "mbuf.ih"

int Mbuf::sync()
{
    d_ostr.flush();
    d_firstChar = true;

    return 0;
}
