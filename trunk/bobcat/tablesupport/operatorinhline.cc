#include "tablesupport.ih"

TableSupport &FBB::operator<<(TableSupport &support, 
                         TableSupport::HLine const &hline)
{
    if (hline.d_begin >= hline.d_end)
        return support;

    vector<size_t> &elements = support.d_elements[hline.d_row];
    size_t nCols = max(hline.d_end, support.d_nColumns);

    elements.resize(1 + TableSupport::rightSeparator(nCols));

    TableSupport::leftType(
        &elements[TableSupport::leftSeparator(hline.d_begin)], hline.d_type);

    int end = TableSupport::leftSeparator(hline.d_end);

    TableSupport::rightType(&elements[end], hline.d_type);
        
    for 
    (
        int idx = TableSupport::element(hline.d_begin);
            idx != end; 
                ++idx
    )
        elements[idx] = TableSupport::USE;

    return support;
}

