#include "main.hh"

void typeDefList(ostream &out, size_t nArgs, size_t nNoDefault, 
                                             char const *defaultType) 
{
    out << '<';
    list(out, nNoDefault, "typename T");
    out << ", ";

    for (size_t idx = nNoDefault + 1; idx < nArgs; ++idx)
        out << "typename T" << idx << defaultType << ", ";

    out << "typename T" << nArgs << defaultType <<
           '>';
}

