#include "glob.ih"

Glob &Glob::operator=(Glob const &&tmp)
{
    static bool called = false;
    deprecated__(called, "Glob::operator=(Glob const &&tmp) is deprecated. "
                         "Please recompile this program");

    swap(const_cast<Glob &>(tmp));
    return *this;
}
