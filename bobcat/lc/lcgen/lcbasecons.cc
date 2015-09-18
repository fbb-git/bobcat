#include "main.hh"

                // Define constructor:

                //     4 (on entry into this function)
                // gen:
                //      inline LCBase(T1 t1, T2 t2, T3 t3)
                //                 12  
                //      :
                //     4
                //          LCBase<T1, T2, Unspecified>(t1, t2),
                //         8    12
                //          f3(t3)
                //         8
                //      {}
                //     4

void lcBaseCons(std::ostream &out, size_t nargs, size_t argsTot)
{
    out << "inline LCBase" << lm(12);
    parList(out, nargs);
    out << '\n' << 
            lm(4);
    
    out << ":\n" <<
            lm(8);

    if (nargs > 2)
    {
        out << "LCBase" << flush << lm(12);
        typeList(out, nargs - 1, argsTot - (nargs - 1));
        out << '\n';
        argList(out, nargs - 1);
        out << ",\n" << 
            lm(8);
    }
    else
        out << "f1(t1),\n";

    out << "f" << nargs << "(t" << nargs << ")\n" << 
            lm(4) <<
        "{}\n";
}
