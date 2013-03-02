#include "string.ih"

    // We're at a separator. Return the iterator pointing beyond the
    // separator. find_first_not_of() will do that, unless there are no
    // non-blanks anymore. In that case, find_first_pos() returns npos,
    // and end() must be returned.
String::const_iterator String::separator(const_iterator from, 
                                         string const &separators) const
{
    size_type idx = find_first_not_of(separators, from - begin());
    return idx == npos ? end() : begin() + idx;
}

