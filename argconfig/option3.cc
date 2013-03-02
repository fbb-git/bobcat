#include "argconfig.ih"

// same as Arg::option's equivalent

size_t ArgConfig::option(string *value, int optChar) const
{
    size_t ret = Arg::option(0U, value, optChar);

    if (ret != 0)
        return ret;

    const_RE_iterator longOpt = findLongOption(optChar);
    if (longOpt == endRE())
        return 0;

    *value = findKeyTail(d_longOption.find(optChar)->second, 0);
    return endRE() - longOpt;
}
