#include "string.ih"

std::vector<std::string> String::split(
                                    Type *type, std::string const &str,
                                    char const *sep, bool addEmpty)
{
    return split(type, str, addEmpty ? TOKSEP : TOK, sep);
}

