#include "pattern.hh"

void Pattern::setPattern(string const &pattern, 
        bool caseSensitive, size_t nSub, int options)
{
    delete [] d_subExpression;
    d_subExpression =   new regmatch_t[nSub];
    d_nSub =            nSub;
    d_beyondLast =      0;

    if (--d_regex->d_referenceCount == 0)
        delete d_regex;

    newRegex(pattern, options | (caseSensitive ? 0 : REG_ICASE));
    d_matchOptions = 0;
}
