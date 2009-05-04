#include "socketbase.ih"

void SocketBase::verify() const
{
    if (d_msg)
        throw Errno(1, d_msg);
}
