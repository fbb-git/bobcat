#include "tablesupport.ih"

TableSupport &TableSupport::operator=(TableSupport &&tmp)
{
    fswap(*this, tmp, d_elements);
    return *this;
}

