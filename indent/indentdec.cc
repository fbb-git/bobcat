#include "indent.hh"


ostream &FBB::indentdec(ostream &out)
{
    out << indent;
    Indent::dec();
    return out;
}





