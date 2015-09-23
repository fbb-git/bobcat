#include "hostent.hh"

size_t Hostent::countAddresses(char const * const *addresses, 
                                                    size_t length) const
{
    PTR  p = {addresses};
    size_t n = 1;                 // counts the final 0-address

    while 
    (
        static_cast<size_t>(count(p.p1, p.p1 + length, char())) != length
    ) 
    {
        p.p1 += length;
        n++;
    }
    return n;
}
