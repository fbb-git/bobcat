#include "string.ih"

char const **String::argv(std::vector<std::string> const &lines)
{
    unsigned idx = lines.size();

    char const **ret = new char const *[idx + 1];
    ret[idx] = 0;

    for (; idx--; )
        ret[idx] = lines[idx].c_str();

    return ret;
}

