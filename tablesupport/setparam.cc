#include "tablesupport.ih"

void TableSupport::setParam(std::ostream &ostr, size_t rows, size_t nColumns,
                            std::vector<Align> const &align)
{
    d_streamPtr = &ostr;
    d_nRows = rows;
    d_nColumns = nColumns,
    d_align = &align,
    
    d_tableWidth = accumulate(align.begin(), align.end(), 0);

    for_each(d_elements.begin(), d_elements.end(), 
        FnWrap::unary(setCols, d_nColumns));

    for_each(d_sep.begin(), d_sep.end(), FnWrap::unary(add, d_tableWidth));
}


