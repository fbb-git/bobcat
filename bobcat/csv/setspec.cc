#include "csv.ih"

void CSV::setSpec(string const &spec)
{
    d_field.clear();
    d_available.clear();

    istringstream in(spec);

    while (true)
    {
        char ch;

        if (not (in >> ch))
            break;

        ch = toupper(ch);
        if (string("SIDX-").find(ch) == string::npos)
            throw Exception() << "CSV: specification `" << spec << 
                                                        "' not supported";
        size_t repeat;
        if (not (in >> repeat))
        {
            in.clear();
            repeat = 1;
        }
        
        d_type.append(repeat, ch);
    }
}
