#include "csv.ih"

CSV &CSV::append(char spec, std::string const &value)
{
    spec = toupper(spec);
    if (string("SIDX-").find(spec) == string::npos)
        throw Exception() << "CSV: specification `" << spec << 
                                                        "' not supported";

    d_type += spec;

    store(d_field.size(), value);

    return *this;                
}





