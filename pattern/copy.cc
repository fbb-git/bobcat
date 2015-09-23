#include "pattern.hh"

void Pattern::copy(Pattern const &other)
{    
    d_regex = other.d_regex;
    d_regex->d_referenceCount++;

    d_nSub = other.d_nSub,
    d_beyondLast =other.d_beyondLast;
    d_text = other.d_text;

    d_subExpression = new regmatch_t[d_nSub];

    std::copy(other.d_subExpression, other.d_subExpression + d_nSub,
            d_subExpression);
}
