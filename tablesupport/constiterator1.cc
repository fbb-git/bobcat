#include "tablesupport.hh"

TableSupport::const_iterator::const_iterator(TableSupport const &support, 
                size_t row, bool begin)
:
    d_support(support)
{
    UMIter iter = support.d_elements.find(row);

    if (iter != support.d_elements.end())
    {
        d_vector =  &iter->second;
        d_iter = begin ? d_vector->begin() : d_vector->end();
    }
    else
    {
        d_vector = &s_empty;
        d_iter = s_empty.end();
    }
}

