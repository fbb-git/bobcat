#include "string.ih"

string String::join(vector<string> const &words, char sep)
{
    string ret;

    if (words.empty())
        return ret;

    auto begin = words.begin();
    ret = *begin++;

    for (auto const &end = words.end(); begin != end; ++begin)
        (ret += sep) += *begin;

    return ret;
}


