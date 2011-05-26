#include "milter.ih"

sfsistat Milter::mClose(SMFICTX *ctx)
{
    iterator it = s_map.find(ctx);
    sfsistat ret = SMFIS_CONTINUE;

    if (it != s_map.end())          // installed.
    {
        if (s_callClose)
            ret = it->second->close();
        
        delete it->second;          // delete this Milter
        s_map.erase(it);            // and erase from the map
    }
    return ret;
}
