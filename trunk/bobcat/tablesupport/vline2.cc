#include "tablesupport.ih"

void TableSupport::vline() const
{
    vline(d_nColumns);
    out() << '\n';
}

