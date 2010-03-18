#include "pattern.ih"

Pattern::Pattern()
:
    d_subExpression(0),
    d_nSub(0),
    d_beyondLast(0)
{
    newRegex("\\b", 0);     // for the benefit of MACs: \\b prevents
}                           // the `empty subexpression' error.
