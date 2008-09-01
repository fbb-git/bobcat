#include "socketbase.ih"

SocketBase::SocketBase(uint16_t port)
:
    InetAddress(port),
    d_msg(0)
{
    d_sock = ::socket(AF_INET, SOCK_STREAM, 0);   // 0: protocol, should be 0

    if (d_sock < 0)
        d_msg = "SocketBase::SocketBase(port)";
}
