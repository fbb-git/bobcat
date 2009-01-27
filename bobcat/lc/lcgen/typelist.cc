#include "main.ih"

void typeList(ostream &out, size_t nTs, size_t nUnspec)
{
    out << '<' << lmargin(+4, lmargin::CHG);

    list(out, nTs, "T");

    if (nUnspec)
    {
        out << ", ";
        listUnspec(out, nUnspec);
    }
    out << '>' << lmargin(-4, lmargin::CHG);
}

