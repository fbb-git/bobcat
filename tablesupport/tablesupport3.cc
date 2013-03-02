#include "tablesupport.ih"

#include "../iuo/iuo"

TableSupport::TableSupport(TableSupport const &&tmp)
:
    d_streamPtr(tmp.d_streamPtr),
    d_nRows(tmp.d_nRows),
    d_nColumns(tmp.d_nColumns),
    d_align(tmp.d_align),

    d_tableWidth( move(tmp.d_tableWidth) ),
    d_elements( move(tmp.d_elements) )
{
    static bool called = false;
    deprecated__(called, 
                "TableSupport::TableSupport(TableSupport const &&tmp)");
}

