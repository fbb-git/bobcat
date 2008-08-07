#include "indent.ih"

ostream &FBB::indentinc(ostream &out)
{
    out << indent;
    Indent::inc();
    return out;
}

