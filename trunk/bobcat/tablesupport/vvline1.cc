#include "tablesupport.ih"

void TableSupport::v_vline() const
{
    vline(d_nColumns);
    out() << '\n';
}

