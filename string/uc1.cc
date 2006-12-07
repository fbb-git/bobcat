#include "string.ih"

string String::uc(string const &lhs)
{
    string ret(lhs);

    for_each(ret.begin(), ret.end(), Wrap1<char>(&String::toupper));

    return ret;
}

