#include "indent.hh"

ostream &FBB::indentinc(ostream &out)
{
    out << indent;
    Indent::inc();
    return out;
}

