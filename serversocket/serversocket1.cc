#include "serversocket.hh"

ServerSocket::ServerSocket(size_t port)
:
    SocketBase(port),       // uses INADDR_ANY -> current host.
    d_msg(0)
{
    int val = 1;    
                            // Make sure the socket is reusable upon restarts
    if (setsockopt(socket(), SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)))
    {
        d_msg = "ServerSocket::ServerSocket(port) setsockopt() failed";
        return;
    }

    if (bind(socket(), sockaddrPtr(), size()) < 0)
        d_msg = "ServerSocket::ServerSocket(port)";
}
