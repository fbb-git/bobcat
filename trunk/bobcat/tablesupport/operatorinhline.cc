#include "tablesupport.ih"

TableSupport &FBB::operator<<(TableSupport &support, 
                         TableSupport::HLine const &hline)
{
    support.d_hline[hline.d_row].push_back(
        TableSupport::BeginEnd(hline.d_begin, hline.d_end)
    );
    return support;
}

