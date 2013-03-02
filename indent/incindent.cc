#include "indent.ih"

std::ostream &FBB::incindent(std::ostream &out)
{
    Indent::inc();
    return out << indent;
}

