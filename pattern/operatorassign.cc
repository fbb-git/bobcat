#include "pattern.hh"

Pattern &Pattern::operator=(Pattern const &other)
{
    Pattern tmp(other);
    swap(tmp);
    return *this;    
}
