#include "string.ih"

string String::escape(string const &str, char const *series)
{
    string ret;
    string::size_type left = 0;

    while (true)
    {
        string::size_type right = str.find_first_of(series, left);

        ret += str.substr(left, right - left);  // append until separator

        if (right == string::npos)                  // done when all copied
            return ret;

        ret += "\\";                        // append backslash
        ret += str[right];                  // append the special char
        left = right + 1;
    }
}


