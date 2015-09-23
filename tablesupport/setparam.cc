#include "tablesupport.hh"

void TableSupport::setParam(std::ostream &ostr, size_t rows, size_t nColumns,
                            std::vector<Align> const &align)
{
    d_streamPtr = &ostr;
    d_nRows = rows;
    d_nColumns = nColumns;
    d_align = &align;
    
    d_tableWidth = accumulate(align.begin(), align.end(), 0);

    for (auto &elements: d_elements)
        elements.second.resize(rightSeparator(d_nColumns) + 1);  

    for (auto &src: d_sep)
        d_tableWidth += src.length();  
}


