#include "mbuf.ih"

int Mbuf::sync()
{
    d_ostr.flush();
    d_newMsg = true;

    return 0;
}
