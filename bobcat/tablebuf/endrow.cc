#include "tablebuf.ih"

void TableBuf::endRow()
{
    d_string.resize(
        ((d_string.size() + d_nColumns - 1) / d_nColumns + 1) * d_nColumns);
}
