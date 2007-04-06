#include "table.ih"
#include <iostream>

Table &Table::sync()
{
    if (d_tabulated || !d_string.size())    // no elements or already 
        return *this;                       // tabulated then do nothing

    d_nRows = (d_string.size() + d_nColumns - 1) / d_nColumns;
    d_string.resize(d_nRows * d_nColumns);  // enforce complete table

                                            // determine max width per column,
                                            // max column width, and alignment
    size_t maxWidth = 0;
    
    for (size_t col = 0; col < d_nColumns; col++)
    {
        size_t maxColWidth = 0;
        for (size_t row = 0; row < d_nRows; row++)
        {
            Element &element = elementAt(row, col);

            size_t len = element.length();
            if (maxColWidth < len)
                maxColWidth = len;
        }
        d_align[col].setWidth(maxColWidth);

                                        // max. width so far.
        if (d_widthType == EQUALWIDTH && maxWidth < maxColWidth)
            maxWidth = maxColWidth;
    }

    if (d_widthType == EQUALWIDTH)
    {
        for (size_t col = 0; col < d_nColumns; col++)
            d_align[col].setWidth(maxWidth);
    }

    d_tabulated = true;
    return *this;
}






