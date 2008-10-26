#include "configfile.ih"

size_t RE_iterator::operator-(RE_iterator const &begin) const
{
    RE_iterator tmp(begin);

    size_t count = 0;
    while (tmp != *this)
    {
        if (tmp.d_current == d_end)
            return UINT_MAX;
        ++tmp;
        ++count;
    }
    return count;
}
