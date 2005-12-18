#include "arg.ih"

unsigned Arg::firstNonEmpty(unsigned *idx, string *value, 
                            StringVector const &sv) const
{
    StringVector::const_iterator sit = find_if(sv.begin(), sv.end(), 
                                         bind2nd(not_equal_to<string>(), ""));
    if (sit == sv.end())
        *idx = sv.size();
    else
    {
        *idx = sit - sv.begin();
        *value = *sit;
    }
        
    return sv.size();
}
