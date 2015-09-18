#include "glob.hh"

Glob &Glob::operator=(Glob &&tmp)
{
    swap(tmp);
    return *this;
}
