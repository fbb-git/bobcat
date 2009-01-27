#include "main.ih"

void lcBase(ostream &out, size_t nargs)
{
    if (nargs < 3)
        throw Errno("max. number of arguments must be at least 3");

    for (size_t idx = nargs; idx >= 2; --idx)
    {
        out << "template ";
        typeDefList(out, idx);
        out << "\n" << 
               "struct LCBase";

        if (idx < nargs)
            typeList(out, idx, nargs - idx);
    
        if (idx > 2)
        {
            out << ": public LCBase";
            typeList(out, idx - 1, nargs - (idx - 1));
        }
        out << "\n"
               "{\n";
        
        if (idx == 2)
            out << "    T1 f1;\n";
        
        out << "    T" << idx << " f" << idx << ";\n"
                "\n";
    
        lcBaseCons(out, idx, nargs);
        out << "};\n"
                "\n";
    }

//    out << "typename T" << nargs << "\n"
//           ">\n"
//           "struct LCBase"
//
//           ": public LCBase<\n";
////    inherit(out, nargs - 1);
//
//    out << "{\n"
//           "    T" << nargs << " f" << nargs << "\n"
//           "};\n";
//
////    for (size_t idx = nargs; idx-- > 3; )
////        specialization(out, idx, nargs);
}

    
