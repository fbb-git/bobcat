#include "string.ih"

string String::joinAll(SplitPairVector const &entries, char sep)
{
    string ret;

    auto begin = entries.begin();
    ret = begin++->first;

    for (auto const &end = entries.end(); begin != end; ++begin)
        (ret += sep) += begin->first;

    return ret;
}


