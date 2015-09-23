#include "tablesupport.hh"

TableSupport::TableSupport(TableSupport &&tmp)
:
    d_streamPtr(tmp.d_streamPtr),
    d_nRows(tmp.d_nRows),
    d_nColumns(tmp.d_nColumns),
    d_align(tmp.d_align),

    d_tableWidth( move(tmp.d_tableWidth) ),
    d_elements( move(tmp.d_elements) )
{}

