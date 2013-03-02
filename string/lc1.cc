#include "string.ih"

string String::lc(string const &str)
{
    string ret(str);

    for (auto &ch: ret)
        tolower(ch);

    return ret;
}
