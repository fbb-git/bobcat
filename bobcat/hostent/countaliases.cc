#include "hostent.hh"

size_t Hostent::countAliases(char const * const *alias) const
{
    size_t idx = 1;   // counts the final 0-ptr.

    while (*alias++)
        idx++;

    return idx;
}
