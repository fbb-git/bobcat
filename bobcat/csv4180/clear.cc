#include "csv4180.ih"

void CSV4180::clear(size_t nFields)
{
    d_nRequired = nFields;
    d_data.clear();
    d_header.clear();
    d_str.clear();
}
