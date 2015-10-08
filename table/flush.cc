#include "table.ih"

Table &Table::flush()
{
    push_back(str());
    str("");
    return *this;
}

