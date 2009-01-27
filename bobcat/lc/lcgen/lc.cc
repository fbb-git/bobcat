#include "main.ih"

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
    out << "template " << lmargin(4);

    typeDefList(out, nargs, 2, " = Unspecified");
    out << "\n" << lmargin(0) <<
           "struct LC: public LCBase" << lmargin(12);
    typeList(out, nargs, 0);

    out << "\n" << lmargin(0) <<
        "{\n";

    for (size_t idx = nargs; idx >= 2; --idx)
        lcCons(out, idx, nargs);

    out << lmargin(0) << "};\n"
            "\n";
}

    
