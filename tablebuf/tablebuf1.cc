#include "tablebuf.ih"

TableBuf::TableBuf(TableSupport &tableSupport, size_t nColumns, 
            FillDirection direction, WidthType widthType)
: 
    TableBase(tableSupport, nColumns, direction, widthType),
    d_fs('\b'),
    d_rs('\n'),
    d_buffered(false),
    d_insertEmptyRow(false)
{}

