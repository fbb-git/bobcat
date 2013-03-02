#include "hostent.ih"

unsigned Hostent::countAliases(char const * const *alias) const
{
    unsigned idx = 1;   // counts the final 0-ptr.

    while (*alias++)
        idx++;

    return idx;
}
