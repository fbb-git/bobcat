#include "tablesupport.ih"
#include <iostream>

size_t TableSupport::width(size_t idx) const
{
    return idx & 1 ? colWidth(idx >> 1) : sepWidth(idx >> 1);
}

