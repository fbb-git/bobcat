#include "clientsocket.ih"

ClientSocket::ClientSocket(string const &host, uint16_t port)
:
    SocketBase(host, port)
{}
