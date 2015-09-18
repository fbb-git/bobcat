#include "pattern.hh"

Pattern::Pattern(string const &pattern, bool caseSensitive, size_t nSub,
                 int options)
:
    d_subExpression(new regmatch_t[nSub]),
    d_nSub(nSub),
    d_beyondLast(0),
    d_matchOptions(0)
{
    newRegex(pattern, options | (caseSensitive ? 0 : REG_ICASE));
}

