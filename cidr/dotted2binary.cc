#include "cidr.ih"

size_t Cidr::dotted2binary(std::string const &dotted)
{
    size_t ret = 0;
    istringstream in(dotted);

    for (size_t idx = 0; idx != 4; ++idx)
    {
        size_t byte;

        if (!(in >> byte))
            throw Exception(1) << "Cidr: " << "invalid address: `" << 
                                                            dotted << '\'';
        ret <<= 8;
        ret += byte;

        in.ignore();
    }

    return ret;
}
