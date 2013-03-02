#include "configfile.ih"

// findKeyTail("key:") - 
//                   trimmed text following key. initial ws before
//                   key should not be specified: skipped by findKeyTail.

string ConfigFile::findKeyTail(string const &key, size_t idx) const
{
    static Pattern pattern("^\\s*\\S+\\s+(.*)\\s*$");  // pick 2nd term as [1]

    return searchFor(key, pattern, idx);
}
