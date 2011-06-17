#include "argconfig.ih"

ArgConfig::const_RE_iterator ArgConfig::findLongOption(int optChar)
{
    map<int, string>::const_iterator optIt = d_longOption.find(optChar);

    return optIt == d_longOption.end() ? 
                        endRE() 
                    :
                        longConfigOpt(optIt->second);
}
