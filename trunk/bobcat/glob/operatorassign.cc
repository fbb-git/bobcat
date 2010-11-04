#include "glob.ih"

Glob &Glob::operator=(Glob const &other)
{
    Glob tmp(other);
    swap(tmp);
    return *this;
}
