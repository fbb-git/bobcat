#include "configfile.ih"

// findKeyTail("key:") - 
//                   trimmed text following key. initial ws before
//                   key should not be specified: skipped by findKeyTail.

string ConfigFile::findKeyTail(string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(.*)\\s*$", count);
}
