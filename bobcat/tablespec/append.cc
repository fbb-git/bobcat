#include "tablespec.ih"

void TableSpec::append(string const &str, char const *sep, bool addEmpty)
{
    if (sep == 0)
        sep = " \t";

    vector<string> words;

    String::split(&words, str, sep, addEmpty);

    copy(words.begin(), words.end(), back_inserter(*this)); 
}

