#include "pattern.ih"

void Pattern::destroy()
{
    if (--d_regex->d_referenceCount == 0)
        delete d_regex;

    delete [] d_subExpression;
}
