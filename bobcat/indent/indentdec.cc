#include "indent.ih"


ostream &FBB::indentdec(ostream &out)
{
    out << indent;
    Indent::dec();
    return out;
}





