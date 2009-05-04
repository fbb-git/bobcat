#include "main.ih"

void list(ostream &out, size_t nTs, char const *txt)
{
    for (size_t idx = 1; idx < nTs; ++idx)
        out << txt << idx << ", ";

    out << txt << nTs;
}
