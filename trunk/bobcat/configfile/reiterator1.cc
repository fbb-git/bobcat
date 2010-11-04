#include "configfile.ih"

RE_iterator::RE_iterator(iterator const &begin, iterator const &end,
                         string const &re, bool caseSensitive)
:
    d_current(begin),
    d_end(end),
    d_pattern(re, caseSensitive)
{
    d_current = find();
}
