#include "cgi.ih"

void CGI::get()
{
    vector<string> words;
    String::split(&words, d_query, "&");    // split the q-string

    for (auto &word: words)
        addParam(word);
}
