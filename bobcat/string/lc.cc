#include "string.ih"

String String::lc() const
{
    String ret(*this);

    for_each(ret.begin(), ret.end(), Wrap1<char>(&String::tolower));

    return ret;
}
