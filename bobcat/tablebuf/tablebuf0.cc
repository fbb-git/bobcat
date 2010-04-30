#include "tablebuf.ih"

TableBuf::TableBuf(size_t nColumns, FillDirection direction, 
                                                        WidthType widthType)
:
    TableBase(nColumns, direction, widthType)
{}
