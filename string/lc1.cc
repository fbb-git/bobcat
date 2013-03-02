#include "string.ih"

string String::lc(string const &str)
{
    string ret(str);

    for_each(ret.begin(), ret.end(), String::tolower);

    return ret;
}
