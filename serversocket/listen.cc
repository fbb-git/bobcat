#include "serversocket.ih"

void ServerSocket::listen(size_t backlog, bool blocking) throw (Errno)
{
    static char name[] = "ServerSocket::listen()";

    int sock = socket();

    if (::listen(sock, backlog) < 0)
        throw Errno(name);

    if (blocking)
        return;

    if 
    (
        fcntl
        (
            sock, 
            F_SETFL, 
            fcntl(sock, F_GETFL, 0) | O_NONBLOCK
        ) 
        == -1
    )
        throw Errno(name);
}

