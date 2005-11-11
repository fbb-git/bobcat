#include "localserversocket.ih"

LocalServerSocket::LocalServerSocket(string const &name,
                                    Socket action) throw (Errno)    // 1
:
    LocalSocketBase(name),
    d_unlink(action == UNLINK),
    d_name(name)
{
    if (bind(socket(), sockaddrPtr(), size()) < 0)
        throw Errno("LocalServerSocket::LocalServerSocket(name)");
}
            








