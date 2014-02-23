#include "csv.ih"

CSV::CSV(std::string const &spec, Mode mode)
:
    d_mode(mode)
{
    istringstream in(spec);
    
    while (true)
    {
        char ch;

        if (not (in >> ch))
            break;

        ch = toupper(ch);
        if (string("SID").find(ch) == string::npos)
            throw Exception() << "CSV(\"" << spec << "\"): " << ch << 
                                                    " not supported";
        size_t repeat;
        if (not (in >> repeat))
        {
            in.clear();
            repeat = 1;
        }
        
        d_type.append(repeat, ch);
    }

    d_field.resize(d_type.length());
    d_available.resize(d_type.length());
}




