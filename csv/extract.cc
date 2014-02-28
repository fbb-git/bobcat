#include "csv.ih"

    // called by operator>> to extract a series of CSVs from `in'.
istream &CSV::extract(istream &in)
{
    d_field.clear();
    d_available.clear();

    size_t idx = 0;

    for (size_t end = d_type.length() - ((d_mode & TRAILINGCOMMA) == 0); 
            idx != end;
                ++idx
    )
    {
        string element;

        getline(in, element, ',');          // read all until the next comma.
        store(idx, element);       
    }

    if (not (d_mode & TRAILINGCOMMA))
    {
        string element;
        in >> element;

        store(idx, element);
    }

    if (d_mode & LINE)
        in.ignore(numeric_limits<int>::max(), '\n');

    return in;
}


