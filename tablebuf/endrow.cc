#include "tablebuf.hh"

void TableBuf::endRow()
{
    d_string.resize(
        (
            (d_string.size() + d_nColumns - 1) / d_nColumns 
            + d_insertEmptyRow
        ) * d_nColumns);
    d_insertEmptyRow = true;
}
