#include "csv.ih"

ostream &CSV::insertCount(ostream &out) const
{
    auto iter = d_field.begin();

    for (bool available: d_available)
    {
        if (available)
            out << *iter << ',';

        ++iter;
    }

    return out;
}
