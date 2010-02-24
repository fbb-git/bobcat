#include "argconfig.ih"

size_t ArgConfig::option(int optChar) const
{
    return Arg::option(optChar) + (endRE() - findLongOption(optChar));
}
