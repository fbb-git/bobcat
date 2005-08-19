#include "string.ih"

String String::uc() const
{
    String ret(*this);

    for_each(ret.begin(), ret.end(), Wrap1<char>(&String::toupper));

    return ret;
}

