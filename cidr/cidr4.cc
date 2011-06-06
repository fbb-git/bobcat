#include "cidr.ih"

#include "../iuo/iuo"

Cidr::Cidr(Cidr const &&tmp) 
:
    d_cidr(move(tmp.d_cidr)),
    d_iter(move(tmp.d_iter)),
    d_matched(move(tmp.d_matched)),
    d_last(tmp.d_last)
{
    static bool called = false;
    deprecated__(called, "Cidr::Cidr(Cidr const &&tmp)");
}
