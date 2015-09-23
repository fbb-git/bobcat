#include "tablebase.hh"

TableBase::TableBase(size_t nColumns, FillDirection direction, 
                                                        WidthType widthType)
:
    d_tabulated(false),
    d_nRows(0),
    d_nColumns(nColumns),
    d_widthType(widthType),
    d_align(nColumns),
    d_ptr(new TableSupport()),
    d_tableSupport(*d_ptr),
    d_indexFun(direction == ROWWISE  ? &TableBase::hIndex : 
                                       &TableBase::vIndex)
{}

