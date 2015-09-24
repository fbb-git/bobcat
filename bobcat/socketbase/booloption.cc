#include "socketbase.ih"

bool SocketBase::boolOption(int optname) const
{
    int         value;
    socklen_t   valueSize = sizeof(int);

    if (getsockopt(d_sock, SOL_SOCKET, optname, &value, &valueSize) < 0)
        throw Exception() << "SocketBase::getOption(): " << errnodescr;

    return value != 0;
}
