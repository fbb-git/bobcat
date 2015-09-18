#include "tablesupport.hh"

TableSupport &TableSupport::operator=(TableSupport &&tmp)
{
    fswap(*this, tmp);
    return *this;
}

