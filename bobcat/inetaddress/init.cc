#include "inetaddress.hh"

void InetAddress::init(uint32_t addr, uint16_t port)
{
    d_address.sin_family        = AF_INET;
    d_address.sin_addr.s_addr   = htonl(addr);
    d_address.sin_port          = htons(port);
}
