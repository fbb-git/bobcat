#include "string.ih"

String String::escape(char const *series) const
{
    String ret;
    size_type left = 0;

    while (true)
    {
        size_type right = find_first_of(series, left);

        ret += substr(left, right - left);  // append until separator

        if (right == npos)                  // done when all copied
            return ret;

        ret += "\\";                        // append backslash
        ret += (*this)[right];              // append the special char
        left = right + 1;
    }
}


