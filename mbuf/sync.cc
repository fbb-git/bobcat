#include "mbuf.hh"

int Mbuf::sync()
{
    d_ostr.flush();
    d_firstChar = true;

    return 0;
}
