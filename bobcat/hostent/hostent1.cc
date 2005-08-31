#include "hostent.ih"

Hostent::Hostent()
:
    d_nAliases(0),
    d_nAddresses(0)
{
    h_name = 0;
    h_aliases = 0;
    h_addrtype = 0;
    h_length = 0;
    h_addr_list = 0;
}
