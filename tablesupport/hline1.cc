#include "tablesupport.ih"

TableSupport::HLine::HLine(size_t row, size_t begin, size_t end)
:
    d_row(row),
    d_begin(begin),
    d_end(end),
    d_type(SKIP)
{}

