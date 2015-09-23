#include "glob.hh"

Glob::Glob(Glob &&tmp)
:
    d_share(tmp.d_share)
{
    tmp.d_share = 0;
}
