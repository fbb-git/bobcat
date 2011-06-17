#include "configfile.ih"

RE_iterator &RE_iterator::operator++()
{
    ++d_idx;
    return *this;
}
