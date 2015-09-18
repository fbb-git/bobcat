#include "tablelines.hh"

void TableLines::v_hline(size_t row) const
{
    if (row == 0 || row == nRows())
        out() << setfill('-') << setw(width()) << "-" << setfill(' ');
    else  
    {
        const_iterator iter = begin(row);
        const_iterator beyond = end(row);

        if (iter == beyond)
            return;

        for (auto &field: ranger(iter, beyond))
            outLine(field, out());
    }
    out() << '\n';
}
