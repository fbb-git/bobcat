#include "glob.ih"

Glob &Glob::operator=(Glob &&tmp)
{
    swap(tmp);
    return *this;
}
