#include "pattern.ih"

string Pattern::beyond() const
{
    unsigned
        begin = d_subExpression[0].rm_eo;

    return
        begin < d_text.length() ?
            d_text.substr(begin)
        :
            "";
}
