#include "string.ih"

string String::uc(string const &lhs)
{
    string ret(lhs);

    for (auto &ch: ret)
        toupper(ch);

    return ret;
}

