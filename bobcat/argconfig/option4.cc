#include "argconfig.ih"

size_t ArgConfig::option(string *value, char const *longOption) const
{
    size_t ret = Arg::option(value, longOption);

    if (ret != 0)
        return ret;

    const_RE_iterator optIt = longConfigOpt(longOption);

    ret = endRE() - optIt;
    if (ret != 0)
        *value = findKey(longOption, 0);

    return ret;
}
