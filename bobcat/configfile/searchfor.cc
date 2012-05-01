#include "configfile.ih"

// The keyPat *must* have a (...) subexpression, defining what to return

string ConfigFile__::searchFor(string const &keyPat, size_t count)
{
    string ret;

    if (count == 0)
        throw Errno("findKey/-Tail: count must be > 0");

    beginRE(keyPat);

    if (d_vsIter.size() <= count)
    {
        d_pattern << *d_vsIter[count - 1];
        ret = d_pattern[d_pattern.end() - 1];
    }

    return ret;
}
