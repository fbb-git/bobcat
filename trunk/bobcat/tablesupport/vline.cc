#include "tablesupport.ih"

void TableSupport::vline(size_t col) const
{
    if (col < d_sep.size())
        out() << d_sep[col];
}

