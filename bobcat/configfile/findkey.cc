#include "configfile.ih"

// findKey("key:") - first ws-delimited field following key. initial ws before
//                   key should not be specified: skipped by findKey.

string ConfigFile::findKey(string const &key, size_t idx) const
{
    static Pattern pattern("^\\s*\\S+\\s+(\\S+)");  // pick 2nd term as [1]

    return searchFor(key, pattern, idx);
}
