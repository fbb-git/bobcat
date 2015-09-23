#include "tablebase.hh"

ostream &TableBase::insert(ostream &ostr)
{
    def();

    if (!d_nRows)
        return ostr;

    d_tableSupport.setParam(ostr, d_nRows, d_nColumns, d_align);

    for (size_t row = 0; row < d_nRows; ++row)
    {
        d_tableSupport.hline(row);

        for (size_t col = 0; col < d_nColumns; ++col)
        {
            size_t colwidth = columnWidth(col);

            d_tableSupport.vline(col);
            Element &element = elementAt(row, col);

            Manipulator manip = element.d_manip;
            if (!manip)
                manip = columnManip(col);

            if (manip != FBB::center)
                ostr << manip << setw(colwidth) << element.d_text;
            else
            {
                int available = colwidth - element.length();
                if (available < 0)
                    available = 0;

                if (size_t skip = available >> 1)
                    ostr << setw(skip) << " ";
        
                ostr << element.d_text;

                if (size_t skip = available - (available >> 1))
                    ostr << setw(skip) << " ";
            }
        }

        d_tableSupport.vline();
    }
    d_tableSupport.hline();

    return ostr;
}


