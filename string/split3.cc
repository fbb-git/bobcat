#include "string.ih"

size_t String::split(SplitPairVector *entries, string const &str, 
                     SplitType stype, char const *sep)
{
    entries->clear();                 // clear the destination vector

    return process(entries, stype, str, sep).entries->size();
}

