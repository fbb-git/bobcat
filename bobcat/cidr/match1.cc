#include "cidr.hh"

bool Cidr::match(istream &in)
{
    auto end = istream_iterator<StringLine>();

    return end != find_if(
                    istream_iterator<StringLine>(in), end, 
                    [this](string const &line)
                    {
                        return this->matchLine(line);
                    }
                  );
}
