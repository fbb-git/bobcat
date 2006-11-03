#include "tablespec.ih"

void TableSpec::append(String const &str, char const *sep, bool addEmpty)
{
    if (sep == 0)
        sep = " \t";

    vector<string> words;

    str.split(&words, sep, addEmpty);

    copy(words.begin(), words.end(), back_inserter(*this)); 
}

