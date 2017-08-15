#include "string.ih"

String::FSAData String::process(SplitPairVector *entries, SplitType stype,
                                string const &str, char const *sep)
{
    FSAData ret{ START, sep, SplitPair{}, entries, str.begin(), str.end() };

    while ((*s_FSAtransition[ret.state]
                            [static_cast<size_t>(peek(ret))])(ret)
    )
        ;

    (*s_tuneToSplitType[stype])(entries);

    return ret;
}
