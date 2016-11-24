#include "tablesupport.ih"

namespace FBB
{

TableSupport &operator<<(TableSupport &support, std::string const &sep)
{
    support.d_sep.push_back(sep);
    --support.d_tableWidth;
    return support;
}

}
