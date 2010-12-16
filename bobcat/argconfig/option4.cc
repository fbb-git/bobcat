#include "argconfig.ih"

size_t ArgConfig::option(string *value, char const *longOption)
{
    size_t ret = Arg::option(value, longOption);

    if (ret != 0)
        return ret;

    const_RE_iterator optIt = longConfigOpt(longOption);

    ret = endRE() - optIt;
    if (value && ret != 0)
        *value = findKeyTail(longOption, 0);

    return ret;
}
