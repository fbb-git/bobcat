#include "configfile.ih"

string ConfigFile::searchFor(string const &key, Pattern &pattern, 
                                                            size_t idx) const
{
    const_RE_iterator iter = beginRE("^\\s*" + key);

    while (idx--)
    {
        if (iter == endRE())
            return "";
        ++iter;
    }

    pattern << *iter;
    return pattern[1];
}
