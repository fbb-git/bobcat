#include "tablesupport.ih"

#include "../iuo/iuo"

TableSupport &TableSupport::operator=(TableSupport const &&tmp)
{
    static bool called = false;
    deprecated__(called, "TableSupport::operator=(TableSupport const &&tmp) "
                        "is deprecated. Please recompile this program");
    fswap(*this, const_cast<TableSupport &>(tmp));
    return *this;
}

