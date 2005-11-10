#include "localserversocket.ih"

LocalServerSocket::LocalServerSocket(string const &name) throw (Errno)    // 1
:
    LocalSocketBase(name)
{
    if (bind(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("LocalServerSocket::LocalServerSocket(name)");
}
            








