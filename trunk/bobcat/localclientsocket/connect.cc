#include "localclientsocket.ih"

int LocalClientSocket::connect()
{
    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("LocalClientSocket::connect()");

    return socket();
}






