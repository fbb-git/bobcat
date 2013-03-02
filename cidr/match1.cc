#include "cidr.ih"

bool Cidr::match(istream &in)
{
    auto end = istream_iterator<StringLine>();

    return end != find_if(
                      istream_iterator<StringLine>(in), end, 
                      FnWrap::unary(matchLine, *this)
                  );
}
