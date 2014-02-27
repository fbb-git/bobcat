#include "csv.ih"

ostream &CSV::insertSize(ostream &out) const
{
    char const *sep = "";

    for (auto const &str: d_field)
    {
        cout << sep;

        if (str.empty())
            out << ' ';
        else
            out << str;
        sep = ",";
    }

    if (d_mode & LINE)
        cout << ',';

    return out;
}
