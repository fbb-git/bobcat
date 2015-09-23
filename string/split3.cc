#include "string.hh"

vector<String::SplitPair> String::split(string const &str,
                                    string const &separators, bool addEmpty)
{
    vector<SplitPair> ret;

                                // visit all chars of str
    for (ConstIter begin = str.begin(), end = str.end(); begin != end; )
    {
        SplitPair next = split(begin, str.end(), separators);

        if (next.second == SEPARATOR && not addEmpty)
            continue;
    
        ret.push_back(next);
    }

    return ret;
}
