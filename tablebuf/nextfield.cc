#include "tablebuf.hh"

void TableBuf::nextField()
{
    d_tabulated = false;
    d_string.push_back(d_str);
    d_str.erase();
    d_buffered = false;

}
