#include "cidr.ih"

void Cidr::setCidr(istream &fin)
{
    d_cidr.clear();

    for_each(
        istream_iterator<StringLine>(fin), istream_iterator<StringLine>(),
        [this](string const &cidrPattern)
        {
            this->pushCidr(cidrPattern);
        }
    );

    if (d_cidr.empty())
        throw Errno(1, "Cidr: ") << "no CIDR patterns found on "
                                        "cidr-specifications stream";
}
