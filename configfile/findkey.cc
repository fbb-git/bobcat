#include "configfile.ih"

// findKey("key:") - first ws-delimited field following key. initial ws before
//                   key should not be specified: skipped by findKey.

string ConfigFile::findKey(string const &keyPattern, size_t count)
{
    return searchFor("^\\s*" + keyPattern + "\\s+(\\S+)", count);
}
