#include "string.ih"

String::SplitPairVector String::split(string const &str, SplitType stype,
                                      char const *sep)
{
    SplitPairVector ret;

    process(&ret, stype, str, sep);

    return ret;
}

