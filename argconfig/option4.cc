#include "argconfig.hh"

size_t ArgConfig::option(string *value, char const *longOption)
{
    size_t ret = Arg::option(value, longOption);

    if (ret != 0)
        return ret;

    auto iterators = longConfigOpt(longOption);

    ret = iterators.second - iterators.first;
    if (value && ret != 0)
        *value = findKeyTail(string(longOption) + ":?", 1);

    return ret;
}
