#include "pattern.ih"

Pattern::Position Pattern::position(size_t index) const
{
    regoff_t begin;

    return
        (
            index >= d_beyondLast || 
            (begin = d_subExpression[index].rm_so) == -1
        ) ?
            Position(string::npos, string::npos)
        :
            Position(begin, d_subExpression[index].rm_eo);
}
