#include "configfile.hh"

RE_iterator &RE_iterator::operator++()
{
    ++d_idx;
    return *this;
}
