#include "csv.hh"

ostream &CSV::insertLength(ostream &out) const
{
    auto iter = d_field.begin();

    char const *sep = "";

    for (char ch: d_type)
    {
        cout << sep;
        if (ch == 'X')
            out << ' ';
        else
        {
            if (iter->empty())
                out << ' ';
            else
                out << *iter;
            ++iter;
        }
        sep = ",";
    }

    if (d_mode & TRAILINGCOMMA)
        cout << ',';

    return out;
}
