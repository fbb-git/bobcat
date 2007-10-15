#include "table.ih"

Table::Table(TableSupport &tableSupport, size_t nColumns, 
            FillDirection direction, WidthType widthType)
: 
    d_tabulated(false),
    d_nRows(0),
    d_nColumns(nColumns),
    d_widthType(widthType),
    d_align(nColumns),
    d_ptr(0),
    d_tableSupport(tableSupport),
    d_indexFun(direction == ROWWISE  ? &Table::hIndex : &Table::vIndex)
{}




