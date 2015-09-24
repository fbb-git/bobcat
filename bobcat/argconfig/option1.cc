#include "argconfig.ih"

size_t ArgConfig::option(int optChar)
{
    auto iterators = findLongOption(optChar);

    return Arg::option(optChar) + (iterators.second - iterators.first);
}
