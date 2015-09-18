#include "main.hh"

void lcBase(ostream &out, size_t nargs)
{
    for (size_t idx = nargs; idx >= 2; --idx)
    {
                // Define (nrs below line indicate lmargin settings):
                //      template <typename T1, typename T2, typename T3>
                //                4                                     
                //      struct LCBase: public LCBase<T1, T2, Unspecified>
                //     0                          12
                //      {
                //     0

        out << "template " << lm(4);
        typeDefList(out, idx);
        out << "\n" << lm(0) <<
               "struct LCBase";

        if (idx == 2)                    // the final specialization
            typeList(out, idx, nargs - idx);
        else                            // the other specializations
        {
            if (idx == nargs)            // all but the first struct starts
                out << ": ";            // on a new line.
            else
            {                           // the 2nd, 3rd: specializations
                out << lm(12);
                typeList(out, idx, nargs - idx);
                out << ':' << lm(4) << '\n';
            }

                                        // inherit from the next special.
            out << "public LCBase" << lm(12);
            typeList(out, idx - 1, nargs - (idx - 1));
        }
    
        out << lm(0) << "\n"
               "{\n" <<
                lm(4);
        

                // Define variable(s): and constructor:
                //      T3 f3;
                //     4   

        if (idx == 2)
            out << "T1 f1;\n";
        
        out << "T" << idx << " f" << idx << ";\n"
                "\n";
    
        lcBaseCons(out, idx, nargs);            // define the constructor
        
        out << lm(0) << "};\n"             // end the LCBase class
                "\n";
    }
}

    
