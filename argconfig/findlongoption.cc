#include "argconfig.ih"

ArgConfig::const_RE_iterator ArgConfig::findLongOption(int optChar) const
{
    map<int, string>::const_iterator optIt = d_longOption.find(optChar);

    return longConfigOpt(optIt->second);
}
