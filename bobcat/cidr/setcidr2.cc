#include "cidr.ih"

void Cidr::setCidr(istream &fin)
{
    d_cidr.clear();

    for_each(istream_iterator<string>(fin), istream_iterator<string>(),
        FnWrap::unary(pushCidr, *this));

    if (d_cidr.empty())
        throw Errno(1, "Cidr: ") << "no CIDR patterns found on "
                                        "cidr-specifications stream";
}
