#include "csv.hh"

ostream &CSV::insertCount(ostream &out) const
{
    auto iter = d_field.begin();

    char const *sep = "";

    for (bool available: d_available)
    {
        cout << sep;

        if (available)
            out << *iter;

        sep = ",";        
        ++iter;
    }

    if (d_mode & TRAILINGCOMMA)
        cout << ',';

    return out;
}
