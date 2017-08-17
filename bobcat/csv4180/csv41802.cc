#include "csv4180.ih"

CSV4180::CSV4180(bool header, size_t nFields)
:
    d_nRequired(nFields),
    d_setHeader(header)
{}
