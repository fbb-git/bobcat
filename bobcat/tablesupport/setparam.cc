#include "tablesupport.ih"
#include <iostream>

void TableSupport::setParam(std::ostream &ostr, size_t rows, size_t nColumns,
                            std::vector<Align> const &align)
{
    d_streamPtr = &ostr;
    d_nRows = rows;
    d_nColumns = nColumns,
    d_align = &align,
    
    d_tableWidth = accumulate(align.begin(), align.end(), 0);

    for_each(d_sep.begin(), d_sep.end(),
        FnWrap1c<string const &, size_t &>(add, d_tableWidth));
}


