#include "tablesupport.ih"

TableSupport &TableSupport::operator=(TableSupport &&tmp)
{
    fswap(*this, tmp);
    return *this;
}

