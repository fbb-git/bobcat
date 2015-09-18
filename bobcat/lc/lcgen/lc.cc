#include "main.hh"

//  Define: (lmargin values under the lines)
//
//              template <typename T1, typename T2, typename T3 = Unspecified>
//             0        4
//              struct LC: public LCBase<T1, T2, T3>
//             0                      12
//              {
//             0

//                  lcCons()

//              };
//             0


void lc(ostream &out, size_t nargs)
{
    out << "template " << lm(4);

    typeDefList(out, nargs, 2, " = Unspecified");
    out << "\n" << lm(0) <<
           "struct LC: public LCBase" << lm(12);
    typeList(out, nargs, 0);

    out << "\n" << lm(0) <<
        "{\n";

    for (size_t idx = nargs; idx >= 2; --idx)
        lcCons(out, idx, nargs);

    out << lm(0) << "};\n"
            "\n";
}

    
