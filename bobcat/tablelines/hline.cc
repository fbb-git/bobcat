#include "tablelines.ih"

void TableLines::hline(size_t row) const
{
    if (row == 0 || row == nRows())
        out() << setfill('-') << setw(width()) << "-" << setfill(' ');
    else  
    {
        const_iterator fieldIt = begin(row);

        if (fieldIt == end())
            return;

        for_each(fieldIt, end(), FnWrap::unary(outLine, out()));
    }
    out() << '\n';
}
