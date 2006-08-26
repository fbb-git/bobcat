#include "localserversocket.ih"

void LocalServerSocket::listen(size_t backlog, bool blocking) throw (Errno)
{
    static char name[] = "LocalServerSocket::listen()";

    if (::listen(socket(), backlog) < 0)
        throw Errno(name);

    if (blocking)
        return;

    if                                  // not tested
    (
        fcntl
        (
            socket(), 
            F_SETFL, 
            fcntl(socket(), F_GETFL, 0) | O_NONBLOCK
        ) 
        == -1
    )
        throw Errno(name);
}









