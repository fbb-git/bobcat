#include "tablesupport.hh"

TableSupport &FBB::operator<<(TableSupport &support, size_t width)
{
    support.d_sep.push_back(std::string(width, ' '));
    --support.d_tableWidth;
    return support;
}

