#include "string.ih"

    // We're at a separator. Return the iterator pointing beyond the
    // separator. find_first_not_of() will do that, unless there are no
    // non-blanks anymore. In that case, find_first_pos() returns npos,
    // and end() must be returned.
String::const_iterator String::separator(string const &str, 
                                        const_iterator from, 
                                        string const &separators)
{
    size_type idx = str.find_first_not_of(separators, from - str.begin());
    return idx == npos ? str.end() : str.begin() + idx;
}

