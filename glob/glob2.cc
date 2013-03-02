#include "glob.ih"

Glob::Glob(Glob &&tmp)
:
    d_share(tmp.d_share)
{
    tmp.d_share = 0;
}
