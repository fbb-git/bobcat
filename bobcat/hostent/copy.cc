#include "hostent.ih"

void Hostent::copy(hostent const *other, unsigned n_aliases, 
                                         unsigned n_addresses)
{
    d_nAliases = n_aliases;
    d_nAddresses = n_addresses;

    h_addrtype = other->h_addrtype;
    h_length = other->h_length;
    h_name = xstrdup(other->h_name);

    h_aliases = new char *[d_nAliases];

    for (unsigned idx = 0; idx < n_aliases; idx++)
        h_aliases[idx] = xstrdup(other->h_aliases[idx]);

    reinterpret_cast<void *>(h_addr_list) = 
                memcpy(new char [n_addresses * h_length], 
                       other->h_addr_list, n_addresses * h_length);
}
