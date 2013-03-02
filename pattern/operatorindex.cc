#include "pattern.ih"

string  Pattern::operator[](unsigned index) const
{
    regoff_t
        begin;

    return
        (
            index >= d_beyondLast || 
            (begin = d_subExpression[index].rm_so) == -1
        ) ?
            ""
        :
            d_text.substr(begin, d_subExpression[index].rm_eo - begin);
}
