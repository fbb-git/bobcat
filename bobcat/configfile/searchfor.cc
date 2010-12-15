#include "configfile.ih"

string const &ConfigFile::searchFor(string const &keyPat, size_t count)
{
    static string const empty;

    if (count == 0)
        throw Errno("findKey/-Tail: count must be > 0");

    beginRE(keyPat);

    return d_vsIter.size() <= count ? *d_vsIter[count - 1] : empty;
}
