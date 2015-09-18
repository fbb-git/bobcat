#include "main.hh"

void argList(ostream &out, size_t nTs)
{
    out << '(';
    list(out, nTs, "t");
    out << ')';
}

