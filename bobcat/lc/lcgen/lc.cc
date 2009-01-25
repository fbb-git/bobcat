#include "main.ih"

void lc(ostream &out, size_t nargs)
{
    out << "template ";
    typeDefList(out, nargs, 2, " = Unspecified");
    out << "\n"
           "struct LC: public LCBase";
    typeList(out, nargs, 0);
    out << "\n"
        "{\n";

    for (size_t idx = nargs; idx >= 2; --idx)
        lcCons(out, idx, nargs);

    out << "};\n"
            "\n";
}

    
