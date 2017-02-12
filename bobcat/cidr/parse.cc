#include "cidr.ih"

Cidr::MaskPair Cidr::parse(string const &cidr)
{
    static Pattern sl_empty("^\\s*(#.*)?$");

    MaskPair ret {0, 0};

    if (sl_empty << cidr)               // empty line or comment
        return ret;

    ret = MaskPair{dotted2binary(cidr), 32};

    size_t pos = cidr.find_first_of('/');
    if (pos != string::npos)
    try
    {
        ret.second = stoul(cidr.substr(pos + 1));   // A2x(...)
        ret.first = ret.first >> (32 - ret.second) << (32 - ret.second);
    }
    catch (...)
    {
        throw Exception{1} << "Cidr: " << "invalid CIDR: `" << cidr << '\'';
    }

    return ret;   
}
