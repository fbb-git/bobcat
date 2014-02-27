#include "csv.ih"

ostream &CSV::insertSize(ostream &out) const
{
    for (auto const &str: d_field)
    {
        if (str.empty())
            out << " ,";
        else
            out << str << ',';
    }

    return out;
}
