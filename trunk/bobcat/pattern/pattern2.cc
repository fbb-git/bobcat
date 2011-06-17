#include "pattern.ih"

#include "../iuo/iuo"

Pattern::Pattern(Pattern const &&tmp)
:
    d_regex(tmp.d_regex),
    d_subExpression(tmp.d_subExpression),
    d_nSub(tmp.d_nSub),
    d_beyondLast(tmp.d_beyondLast),
    d_text(tmp.d_text),
    d_matchOptions(tmp.d_matchOptions)
{
    static bool called = false;
    deprecated__(called, "Pattern::Pattern(Pattern const &&tmp)");
    const_cast<Pattern &>(tmp).d_regex = 0;
}
