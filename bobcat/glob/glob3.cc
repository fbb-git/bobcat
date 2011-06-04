#include "glob.ih"

#include "../iuo/iuo"

Glob::Glob(Glob const &&tmp)
:
    d_share(tmp.d_share)
{
    static bool called = false;
    deprecated__(called, "Glob::Glob(Glob const &&tmp) is deprecated. Please "
                         "recompile this program");

    const_cast<Glob &>(tmp).d_share = 0;
}
