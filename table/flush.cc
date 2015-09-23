#include "table.hh"

Table &Table::flush()
{
    push_back(str());
    str("");
    return *this;
}

