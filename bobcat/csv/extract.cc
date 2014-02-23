#include "csv.ih"

istream &CSV::extract(istream &in)
{
    size_t idx = 0;
    for (size_t end = d_type.length() - ((d_mode & TRAILINGCOMMA) == 0); 
            idx != end;
                ++idx
    )
    {
        string element;

        getline(in, element, ',');

        assign(idx, element);
    }

    if (not (d_mode & TRAILINGCOMMA))
    {
        string element;
        in >> element;

        assign(idx, element);
    }

    if (d_mode & LINE)
        in.ignore(numeric_limits<int>::max(), '\n');

    return in;
}


