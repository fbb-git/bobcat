#include "clientsocket.ih"

int ClientSocket::connect() throw (Errno)
{
    if (::connect(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("ClientSocket::connect()");

    return socket();
}






