#include "clientsocket.ih"

int ClientSocket::connect()
{
    verify();               // verify the SocketBase construction

    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("ClientSocket::connect()");

    return socket();
}






