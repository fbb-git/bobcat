#include "tablebuf.hh"

TableBuf::TableBuf(size_t nColumns, FillDirection direction, 
                                                        WidthType widthType)
:
    TableBase(nColumns, direction, widthType),
    d_fs('\b'),
    d_rs('\n'),
    d_buffered(false),
    d_insertEmptyRow(false)
{}
