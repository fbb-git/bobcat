#include "tablesupport.ih"

TableSupport::const_iterator::const_iterator(TableSupport const &support)
:
    d_support(support),
    d_col(support.d_nColumns + 1),
    d_sep(false)
{}

