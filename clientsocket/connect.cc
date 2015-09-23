#include "clientsocket.hh"

int ClientSocket::connect()
{
    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Exception() << "ClientSocket::connect(): " << errnodescr;

    return socket();
}






