#include "inetaddress.ih"

InetAddress::InetAddress(string const &host, uint16_t port)
{
    hostent const *hp = 
        GetHostent::gethostent("InetAddress::InetAddress(host, port)", host);

    init(ntohl(*reinterpret_cast<uint32_t *> (*(hp->h_addr_list))), port);
}
