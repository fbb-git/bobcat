#include "argconfig.ih"

// same as Arg::option's equivalent

size_t ArgConfig::option(string *value, int optChar)
{
    static size_t const zero = 0;       // prevents amd64 ambiguities where 
    size_t ret = Arg::option(zero, value, optChar);     // (size_t)0 != 0U

    if (ret != 0)
        return ret;

    const_RE_iterator longOpt = findLongOption(optChar);
    if (longOpt == endRE())
        return 0;

    if (value)
        *value = findKeyTail(d_longOption.find(optChar)->second, 1);

    return endRE() - longOpt;
}
