#include "csv4180.ih"

CSV4180::CSV4180(size_t nFields, bool header)
:
    d_nRequired(nFields),
    d_setHeader(header)
{}
