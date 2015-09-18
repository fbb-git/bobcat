#include "cidr.hh"

Cidr::Cidr(Cidr &&tmp) 
:
    d_cidr(move(tmp.d_cidr)),
    d_iter(move(tmp.d_iter)),
    d_matched(move(tmp.d_matched)),
    d_last(tmp.d_last)
{}
