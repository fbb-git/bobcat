#include "main.ih"

void typeDefList(ostream &out, size_t nTs)
{
    out << '<' << lmargin(4, lmargin::CHG);
    list(out, nTs, "typename T");
    out << '>' << lmargin(-4, lmargin::CHG);
}

