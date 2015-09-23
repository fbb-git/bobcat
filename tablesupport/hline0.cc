#include "tablesupport.hh"

TableSupport::HLine::HLine(ColumnType margins, 
                            size_t row, size_t begin, size_t end)
:
    d_row(row),
    d_begin(begin),
    d_end(end),
    d_type(margins)
{
    if (d_type & LEFT_FULL)
        d_type &= ~LEFT_MID;

    if (d_type & RIGHT_FULL)
        d_type &= ~RIGHT_MID;

}

