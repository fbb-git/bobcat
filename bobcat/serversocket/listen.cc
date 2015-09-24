#include "serversocket.ih"

void ServerSocket::listen(size_t backlog, bool blocking)
{
    static char name[] = "ServerSocket::listen()";

    verify();               // verify the SocketBase construction

    if (d_msg)
        throw Exception(1) << d_msg;
        
    int sock = socket();

    if (::listen(sock, backlog) < 0)
        throw Exception() << name << ": " << errnodescr;

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
        throw Exception() << name << ": " << errnodescr;
}

