#include "tablelines.ih"

void TableLines::vline() const
{
    vline(nColumns());
    out() << "\n";
}

