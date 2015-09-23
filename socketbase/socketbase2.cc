#include "socketbase.hh"

SocketBase::SocketBase(string const &host, uint16_t port)
:
    InetAddress(host, port)
{
    d_sock = ::socket(AF_INET, SOCK_STREAM, 0);   // 0: protocol, should be 0 
    if (d_sock < 0) 
        throw Exception() << "SocketBase::SocketBase(" << host << ", " << 
                                            port << "): " << errnodescr;
}






