#include "tablesupport.ih"

TableSupport::const_iterator::const_iterator(
            TableSupport const &support, std::vector<BeginEnd> const &field)
:
    d_support(support),
    d_col(0),
    d_sep(true),
    d_begin(field.begin()),
    d_end(field.end())
{
    setElement();
}

