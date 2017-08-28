#include "string.ih"

// static
string String::urlDecode(string const &encoded) 
{
    string ret;

    for (auto begin = encoded.begin(); begin != encoded.end(); ++begin)
    {
        if (*begin != '%')
            ret += *begin;
        else
        {
            string convert{begin + 1, begin + 3};
            begin += 2;
            ret += stoi(convert, 0, 16);
        }            
    }

    return ret;
}



