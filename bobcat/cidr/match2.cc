#include "cidr.ih"

bool Cidr::match(string const &line)
{
    return matchLine(line, *this);
}
