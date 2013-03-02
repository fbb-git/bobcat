#include "glob.ih"

#include "../iuo/iuo"

Glob &Glob::operator=(Glob const &&tmp)
{
    static bool called = false;
    deprecated__(called, "Glob::operator=(Glob const &&tmp)");

    swap(const_cast<Glob &>(tmp));
    return *this;
}
