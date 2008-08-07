#include "table.ih"

Table &Table::setAlign(Align const &align)
{
    d_tabulated = false;
    
    if (align.hasRow())
        elementAt(align.row(), align.col()).d_manip = align.manip();
    else
        d_align[align.col()].setManip(align.manip());

    return *this;
}


