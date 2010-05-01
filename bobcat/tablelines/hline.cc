#include "tablelines.ih"

void TableLines::hline(size_t row) const
{
    if (row == 0 || row == nRows())
        out() << setfill('-') << setw(width()) << "-" << setfill(' ');
    else  
    {
        const_iterator iter = begin(row);
        const_iterator beyond = end(row);

        if (iter == beyond)
            return;

        for_each(iter, beyond, FnWrap::unary(outLine, out()));
    }
    out() << '\n';
}
