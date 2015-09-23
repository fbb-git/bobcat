#include "localserversocket.hh"

void LocalServerSocket::open(string const &name, Socket action)
{
    LocalSocketBase::open(name);
    d_unlink = action == UNLINK;
    d_name = name;

    if (bind(socket(), sockaddrPtr(), size()) < 0)
        throw Exception() << "LocalServerSocket::open(" << name << "): " <<
                                                            errnodescr;
}
            








