#include "string.ih"

string String::join(SplitPairVector const &entries, char sep, bool all)
{
    return entries.empty() ? 
                string{}
            :
                (*s_join[all])(entries, sep);
}


