#include "hostent.ih"

void Hostent::copy(hostent const *other, size_t n_aliases, 
                                         size_t n_addresses)
{
    d_nAliases = n_aliases;
    d_nAddresses = n_addresses;

    h_addrtype = other->h_addrtype;
    h_length = other->h_length;
    h_name = xstrdup(other->h_name);

    h_aliases = new char *[d_nAliases];

    for (size_t idx = 0; idx < n_aliases; idx++)
        h_aliases[idx] = xstrdup(other->h_aliases[idx]);

    h_addr_list = reinterpret_cast<char **>(
                memcpy(new char [n_addresses * h_length], 
                       other->h_addr_list, n_addresses * h_length));
}
