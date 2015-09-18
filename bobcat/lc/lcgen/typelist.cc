#include "main.hh"

void typeList(ostream &out, size_t nTs, size_t nUnspec)
{
    out << '<';

    list(out, nTs, "T");

    if (nUnspec)
    {
        out << ", ";
        listUnspec(out, nUnspec);
    }
    out << '>';
}

