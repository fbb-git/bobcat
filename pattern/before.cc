#include "pattern.ih"

string Pattern::before() const
{
    return d_text.substr(0, d_subExpression[0].rm_so);
}
