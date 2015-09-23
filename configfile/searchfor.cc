#include "configfile.hh"

// The keyPat *must* have a (...) subexpression, defining what to return

string ConfigFile__::searchFor(string const &keyPat, size_t count)
{
    string ret;

    if (count == 0)
        throw Exception() << "findKey/-Tail: count must be > 0";

    beginRE(keyPat);

    if (count <= d_vsIter.size())               // at least 'count' lines
    {                                           // are required
        d_pattern << *d_vsIter[count - 1];      // if so, return the tail of
        ret = d_pattern[d_pattern.end() - 1];   // line[count - 1]
    }

    return ret;
}
