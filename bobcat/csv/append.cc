#include "csv.ih"

CSV &CSV::append(char spec, std::string const &value)
{
    spec = toupper(spec);
    if (string("SID").find(spec) == string::npos)
        throw Exception() << "CSV.append(" << spec << 
                                         "...): specification not supported";

    d_field.push_back(String::trim(value));

    bool ok = true;
    try
    {
        switch (spec)
        {
            case 'I':
                stoll(value);
            break;
                
            case 'D':
                stold(value);
            break;

            case 'S':
                ok = d_field.back().length() != 0;
            break;
        }
    }
    catch (...)
    {
        ok = false;
    }

    d_available.push_back(ok);
    d_type += spec;

    return *this;                
}
