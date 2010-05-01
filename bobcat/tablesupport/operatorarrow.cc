#include "tablesupport.ih"

TableSupport::Field const *TableSupport::const_iterator::operator->() const
{
    d_field = Field { d_support.width(d_iter - d_vector.begin()), *d_iter };
    return &d_field;
}
