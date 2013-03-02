#include "tablesupport.ih"

TableSupport &TableSupport::operator=(TableSupport const &&tmp)
{
    fswap(*this, const_cast<TableSupport &>(tmp));
    return *this;
}

