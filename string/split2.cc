#include "string.ih"

std::vector<String::SplitPair> String::split(
                            std::string const &str,
                            char const *sep, bool addEmpty)
{
    return split(str, addEmpty ? TOKSEP : TOK, sep);
}
