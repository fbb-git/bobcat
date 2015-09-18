#include "milter.hh"

Milter *Milter::install(SMFICTX *ctx)
{
    iterator it = s_map.find(ctx);
    if (it != s_map.end())          // already installed.
        return it->second;

    Milter *mp = s_mp->clone();
    mp->d_ctx = ctx;                // make ctx available to the Milter itself

    return s_map[ctx] = mp;         // return the Milter's address
}
