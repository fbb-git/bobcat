#include "argconfig.hh"

    // return ConfigFile's RE_iterator to the configfile's long option

ArgConfig::RE_iteratorPair ArgConfig::findLongOption(int optChar)
{
            // find the long option given the short option char
    auto optIt = d_ptr->find(optChar);

    return optIt == d_ptr->findEnd() ?        // not found,
                        beginEndRE()
                    :                           // else return an iter to the
                        longConfigOpt(optIt->second);   // option's line.
}
