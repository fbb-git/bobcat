#include "x2a.ih"

X2a::X2a(double x, unsigned wid, unsigned behind)
{
    X2a tmp(x, behind);
    *this << setw(wid) << tmp.str();
}
