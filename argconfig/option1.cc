#include "argconfig.ih"

size_t ArgConfig::option(int optChar)
{
    auto begin = findLongOption(optChar);
    return Arg::option(optChar) + (endRE() - begin);
}
