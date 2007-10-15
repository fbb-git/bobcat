#include "tablesupport.ih"

TableSupport::const_iterator &TableSupport::const_iterator::operator++()
{
    if (!d_sep)
        ++d_col;

    d_sep = not d_sep;

    if (d_begin != d_end && d_col >= d_begin->second)
        ++d_begin;

    setElement();

    return *this;
}

