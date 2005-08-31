#include "socketbase.ih"

bool SocketBase::setBoolOption(int optname, bool newValue) throw (Errno)
{
    bool oldValue = boolOption(optname);

    if (setsockopt(d_sock, SOL_SOCKET, optname, &newValue, sizeof(bool)) < 0)
        throw Errno("SocketBase::getOption()");

    return oldValue;
}
