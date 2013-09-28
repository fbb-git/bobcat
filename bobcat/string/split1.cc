#include "string.ih"

vector<string> String::split(Type *type, string const &str,
                                    string const &separators, bool addEmpty)
{
    vector<string> ret;
    Type localType = NORMAL;

                                // visit all chars of str
    for (ConstIter begin = str.begin(), end = str.end(); begin != end; )
    {
        SplitPair const &next = split(begin, str.end(), separators);

        if (not (addEmpty && next.second == SEPARATOR))
            continue;
    
        ret.push_back(next.first);
        localType = next.second;
    }

    if (type)
        *type = localType == DQUOTE ||
                localType == SQUOTE ||
                localType == SEPARATOR  ? NORMAL : localType;

    return ret;
}

