#include "indent.ih"

ostream &FBB::decindent(ostream &out)
{
    Indent::dec();
    return out << indent;
}
