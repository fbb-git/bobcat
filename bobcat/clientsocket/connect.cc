#include "clientsocket.ih"

int ClientSocket::connect()
{
    verify();               // verify the SocketBase construction

    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Exception() << "ClientSocket::connect()";

    return socket();
}






