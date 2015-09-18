#include "indent.hh"

ostream &FBB::decindent(ostream &out)
{
    Indent::dec();
    return out << indent;
}
