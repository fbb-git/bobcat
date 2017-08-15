#include "string.ih"

string String::joinIgnoreSEPARATOR(SplitPairVector const &entries, char sep)
{
    string ret;

    auto begin = find_if(entries.begin(), entries.end(), 
        [&](SplitPair const &entry)
        {
            return entry.second != SEPARATOR;
        }
    );

    auto end = entries.end();

    if (begin == end || entries.empty())
        return ret;

    ret = begin++->first;

    for ( ; begin != end; ++begin)
    {
        if (begin->second != SEPARATOR)
            (ret += sep) += begin->first;
    }

    return ret;
}


