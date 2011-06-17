#include "main.ih"

void listUnspec(ostream &out, size_t nUnspec)
{
    for (size_t idx = 1; idx < nUnspec; ++idx)
        out << "Unspecified, ";

    out << "Unspecified";
}

