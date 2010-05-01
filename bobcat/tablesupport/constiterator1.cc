#include "tablesupport.ih"

TableSupport::const_iterator::const_iterator(TableSupport const &support, 
                size_t row, bool begin)
:
    d_support(support),
    d_vector(support.d_elements.find(row)->second),
    d_iter(begin ? d_vector.begin() : d_vector.end())
{}

