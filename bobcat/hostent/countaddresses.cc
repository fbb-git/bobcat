#include "hostent.ih"

unsigned Hostent::countAddresses(char const * const *addresses, 
                                                    unsigned length) const
{
    PTR  p = {addresses};
    unsigned n = 1;                 // counts the final 0-address

    while 
    (
        static_cast<unsigned>(count(p.p1, p.p1 + length, char())) != length
    ) 
    {
        p.p1 += length;
        n++;
    }
    return n;
}
