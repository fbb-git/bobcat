#include "tablesupport.ih"

void TableSupport::vline(size_t col) const
{
    if (d_sep.size() < col)
        out() << d_sep[col];
}

