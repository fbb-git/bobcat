#include "configfile.ih"

RE_iterator &RE_iterator::operator++()
{
    ++d_current;
    d_current = find();

    return *this;
}
