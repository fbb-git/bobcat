#include "csv.ih"

ostream &CSV::insertLength(ostream &out) const
{
    auto iter = d_field.begin();

    for (char ch: d_type)
    {
        if (ch == 'X')
        {
            out << " ,";
            continue;
        }

        if (iter->empty())
            out << " ,";
        else
            out << *iter << ',';
        ++iter;
    }

    return out;
}
