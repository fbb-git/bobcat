#include "string.hh"

char const **String::argv(std::vector<string> const &lines)
{
    size_t idx = lines.size();

    char const **ret = new char const *[idx + 1];
    ret[idx] = 0;

    for (; idx--; )
        ret[idx] = lines[idx].c_str();

    return ret;
}

