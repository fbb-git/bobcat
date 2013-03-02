#include "clientsocket.ih"

ClientSocket::ClientSocket(string const &host, uint16_t port) throw (Errno)
:
    SocketBase(host, port)
{}
