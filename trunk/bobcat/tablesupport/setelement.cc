#include "tablesupport.ih"

void TableSupport::const_iterator::setElement()
{
    d_element.type = SKIP;

    if (d_begin != d_end)
    {
        if (d_begin->first == d_col && !d_sep)
            d_element.type = USE;
        else if (d_col + 1 == d_begin->second && !d_sep)
            d_element.type = USE;
        else if (d_begin->first < d_col && d_col < d_begin->second)
            d_element.type = USE;
    }

    d_element.width = d_sep ? 
                            d_support.sepWidth(d_col) 
                        : 
                            d_support.colWidth(d_col);
}

