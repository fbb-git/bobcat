#include "main.ih"

void parList(ostream &out, size_t nTs)
{
    out << '(' << lmargin(4, lmargin::CHG);

    for (size_t idx = 1; idx < nTs; ++idx)
        out << "T" << idx << " t" << idx << ", ";

    out << "T"  << nTs << " t"  << nTs;

    out << ")" << lmargin(-4, lmargin::CHG);
}

