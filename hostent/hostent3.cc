#include "hostent.hh"

Hostent::Hostent(hostent const *other)
{
    copy(other, countAliases(other->h_aliases), 
                countAddresses(other->h_addr_list, other->h_length));
}
