#include "main.ih"

void typeDefList(ostream &out, size_t nTs)
{
    out << '<';
    list(out, nTs, "typename T");
    out << '>';
}

