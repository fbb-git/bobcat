#include "main.ih"

void lcBaseCons(std::ostream &out, size_t nargs, size_t argsTot)
{
    out << lmargin(4, lmargin::CHG) << "inline LCBase";
    parList(out, nargs);
    out << '\n';
    
    out << ":\n";
    if (nargs > 2)
    {
        out << "LCBase";
        typeList(out, nargs - 1, argsTot - (nargs - 1));
        argList(out, nargs - 1);
        out << ",\n";
    }

    if (nargs == 2)
        out << "f1(t1),\n";

    out << "f" << nargs << "(t" << nargs << ")\n" << 
        lmargin(-4, lmargin::CHG) <<
        "    {}\n" << lmargin(4);
}
