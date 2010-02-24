#include "glob.ih"

Glob &Glob::operator=(Glob const &&tmp)
{
    swap(const_cast<Glob &>(tmp));
    return *this;
}
