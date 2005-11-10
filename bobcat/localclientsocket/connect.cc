#include "localclientsocket.ih"

int LocalClientSocket::connect() throw (Errno)
{
    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("LocalClientSocket::connect()");

    return socket();
}






