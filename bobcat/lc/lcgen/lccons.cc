#include "main.hh"

//              0 (from lc.cc)
//
//                  inline LC(T1 t1, T2 t2, T3 t3)
//                 4       12
//                  :
//                       LCBase<T1, T2, T3>(t1, t2, t3)
//                      8    12
//                  {}
//                 4

void lcCons(std::ostream &out, size_t nargs, size_t argsTot)
{
    out << lm(4) << "inline LC" << flush << lm(12);

    parList(out, nargs);
    out << "\n" << lm(4) <<
           ":\n" << lm(8) <<
           "LCBase" << flush << lm(12);

    typeList(out, nargs, argsTot - nargs);
    argList(out, nargs);

    out << "\n" << lm(4) <<
           "{}\n"
           "\n";
}
