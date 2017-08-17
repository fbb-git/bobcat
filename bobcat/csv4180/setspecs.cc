#include "csv4180.ih"

void CSV4180::setSpecs(string const &specs)
{
    istringstream in(specs);

    while (true)
    {
        char ch;

        if (not (in >> ch))                     // skips blanks
            break;

        ch = toupper(ch);

        if (ch == '-')
            ch = 'X';
        else if (string("SIDX").find(ch) == string::npos)
            throw Exception{} << "CSV4180: specification `" << ch << 
                                                        "' not supported";
        size_t repeat;
        if (not (in >> repeat))
        {
            in.clear();
            repeat = 1;
        }
        
        d_specs.append(repeat, ch);
    }

    d_verifyTypes = &CSV4180::verifyTypes;
    d_dropFields = &CSV4180::dropFields;
}
