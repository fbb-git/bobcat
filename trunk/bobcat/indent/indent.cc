#include "indent.ih"

ostream &FBB::indent(ostream &out)
{
    if (Indent::s_width)
        out << setw(Indent::s_width) << ' ';

    return out;
}

