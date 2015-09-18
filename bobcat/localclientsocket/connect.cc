#include "localclientsocket.hh"

int LocalClientSocket::connect()
{
    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Exception() << "LocalClientSocket::connect(): " << errnodescr;

    return socket();
}






