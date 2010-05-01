#include "tablesupport.ih"

TableSupport &FBB::operator<<(TableSupport &support, 
                         TableSupport::HLine const &hline)
{
    vector<size_t> &elements = support.d_elements[hline.d_row];

    elements.resize(TableSupport::leftSeparator(support.d_nColumns));

    TableSupport::leftType(
        &elements[TableSupport::leftSeparator(hline.d_begin)], hline.d_type);
    TableSupport::rightType(
        &elements[TableSupport::leftSeparator(hline.d_end)], hline.d_type);
        
    for 
    (
        size_t idx = TableSupport::element(hline.d_begin),
                end = TableSupport::element(hline.d_end); 
            idx != end; 
                ++idx
    )
        elements[idx] = TableSupport::USE;

    return support;
}

