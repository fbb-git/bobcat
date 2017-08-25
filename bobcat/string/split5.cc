#include "string.ih"

vector<string> String::split(Type *type, string const &str, SplitType stype,
                                    char const *sep)
{
    vector<string> ret;

    SplitPairVector entries;

    auto data{ process(&entries, stype, str, sep) };

    if (type != 0)
        *type = data.entry.second == DQUOTE ||
                data.entry.second == SQUOTE ||
                data.entry.second == SEPARATOR  ? NORMAL : data.entry.second;

    for (auto &entry: entries)
        ret.push_back(move(entry.first));

    return ret;
}

