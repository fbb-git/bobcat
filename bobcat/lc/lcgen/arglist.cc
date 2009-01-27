#include "main.ih"

void argList(ostream &out, size_t nTs)
{
    out << '(' << lmargin(+4, lmargin::CHG);
    list(out, nTs, "t");
    out << ')';
}

