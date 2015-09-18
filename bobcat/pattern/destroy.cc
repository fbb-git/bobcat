#include "pattern.hh"

void Pattern::destroy()
{
    if (d_regex == 0)
        return;

    if (--d_regex->d_referenceCount == 0)
        delete d_regex;

    delete [] d_subExpression;
}
