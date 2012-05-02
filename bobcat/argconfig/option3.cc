#include "argconfig.ih"

// same as Arg::option's equivalent

size_t ArgConfig::option(string *value, int optChar)
{
    static size_t const zero = 0;       // prevents amd64 ambiguities where 
    size_t ret = Arg::option(zero, value, optChar);     // (size_t)0 != 0U

    if (ret != 0)
        return ret;

    auto iterators = findLongOption(optChar);

    if (iterators.second == iterators.first)
        return 0;

    if (value)
        *value = findKeyTail(d_ptr->find(optChar)->second + ":?", 1);

    return iterators.second - iterators.first;
}




