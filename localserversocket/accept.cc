#include "localserversocket.ih"

size_t LocalServerSocket::accept()
{
    sockaddr_un address;

    socklen_t   size = sizeof(address);

    int sock =
            ::accept
            (
                socket(),
                reinterpret_cast<sockaddr *>(&address),
                &size
            );
        
    if (sock < 0)
        throw Exception{} << "LocalServerSocket::accept(): " << errnodescr;

    return sock;
}



