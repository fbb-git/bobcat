#include "x2a.hh"

X2a::X2a(double x, size_t wid, size_t behind)
{
    X2a tmp(x, behind);
    *this << setw(wid) << tmp.str();
}
