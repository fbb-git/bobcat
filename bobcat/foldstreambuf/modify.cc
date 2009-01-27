#include "foldstreambuf.ih"
#include <typeinfo>

std::ostream &lmargin::modify(std::ostream &out) const
{
    if (d_set)
        dynamic_cast<FoldStreambuf &>(*out.rdbuf()).setIndent(d_value);
    else
        dynamic_cast<FoldStreambuf &>(*out.rdbuf()).chgIndent(d_value);

    return out;
}        

