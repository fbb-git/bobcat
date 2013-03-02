#include "socketbase.ih"

SocketBase::SocketBase(uint16_t port)
:
    InetAddress(port)
{
    d_sock = ::socket(AF_INET, SOCK_STREAM, 0);   // 0: protocol, should be 0

    d_msg = d_sock < 0 ? "SocketBase::SocketBase(port)" : 0;
}
