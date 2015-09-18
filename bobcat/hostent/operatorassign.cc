#include "hostent.hh"

Hostent &Hostent::operator=(Hostent const &other)
{
    Hostent tmp(other);
    swap(tmp);
    return *this;
}
