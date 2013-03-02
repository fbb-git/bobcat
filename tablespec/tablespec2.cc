#include "tablespec.ih"

TableSpec::TableSpec(size_t nColumns,
                        FillDirection direction)
:
    d_tableSupportPtr(new TableSupport()),
    d_tableSupport(*d_tableSupportPtr),
    d_maxWidth(0),
    d_nRows(0),
    d_nColumns(nColumns),
    d_widthType(ColumnWidth),
    d_colWidth(nColumns),
    d_widthFun(&TableSpec::columnWidth),
    d_indexFun(direction == Horizontal ? 
                    &TableSpec::hIndex
                :
                    &TableSpec::vIndex)
{}
