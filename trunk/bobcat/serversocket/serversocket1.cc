#include "serversocket.ih"

ServerSocket::ServerSocket(size_t port)
:
    SocketBase(port)        // uses INADDR_ANY -> current host.
{
    int val = 1;    
                            // Make sure the socket is reusable upon restarts
    if (setsockopt(socket(), SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)))
        throw Errno("ServerSocket::ServerSocket(port) setsockopt() failed");

    if (bind(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("ServerSocket::ServerSocket(port)");
}
