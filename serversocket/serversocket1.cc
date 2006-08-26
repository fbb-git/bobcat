#include "serversocket.ih"

ServerSocket::ServerSocket(size_t port) throw (Errno)
:
    SocketBase(port)        // uses INADDR_ANY -> current host.
{
    if (bind(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("ServerSocket::ServerSocket(port)");
}
