#include "string.ih"

size_t String::split(vector<string> *words, string const &str, 
                     SplitType stype, char const *sep)
{
    *words = split(noType, str, stype, sep);
    return words->size();
}

