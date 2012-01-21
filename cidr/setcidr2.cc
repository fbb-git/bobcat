#include "cidr.ih"

void Cidr::setCidr(istream &fin)
{
    d_cidr.clear();

    for (auto &cidrPattern: ranger(
        istream_iterator<StringLine>(fin), istream_iterator<StringLine>())
    )
        pushCidr(cidrPattern);

    if (d_cidr.empty())
        throw Errno(1, "Cidr: ") << "no CIDR patterns found on "
                                        "cidr-specifications stream";
}
