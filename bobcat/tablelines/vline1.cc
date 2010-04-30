#include "tablelines.ih"

void TableLines::vline(size_t col) const
{
    if (col < sep().size())
        out() << sep()[col];
}

