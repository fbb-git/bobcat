#include "pattern.ih"

Pattern::Pattern(Pattern &&tmp)
:
    d_regex(tmp.d_regex),
    d_subExpression(tmp.d_subExpression),
    d_nSub(tmp.d_nSub),
    d_beyondLast(tmp.d_beyondLast),
    d_text(tmp.d_text),
    d_matchOptions(tmp.d_matchOptions)
{
    tmp.d_regex = 0;
    tmp.d_subExpression = 0;
}
