#include "glob.ih"

Glob::Glob(Glob const &&tmp)
:
    d_share(tmp.d_share)
{
    const_cast<Glob &>(tmp).d_share = 0;
}
