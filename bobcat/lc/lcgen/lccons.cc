#include "main.ih"

void lcCons(std::ostream &out, size_t nargs, size_t argsTot)
{
    out << "    inline LC";
    parList(out, nargs);
    out << "\n"
           "    :\n"
           "         LCBase";
    typeList(out, nargs, argsTot - nargs);
    argList(out, nargs);
    out << "\n"
           "    {}\n"
           "\n";
}

        
