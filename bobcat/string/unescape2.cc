#include "string.ih"

String::Unescape String::unescape(ConstIter begin, ConstIter const &end) 
{
                                // no chars, no backslash or nothing beyond
                                // the backslash? Then no escape sequence 
    if (begin == end || *begin != '\\' || ++begin == end) 
        return Unescape{ "", 0 };

                                // a standard escape char
    if (string{ "abfnrtv" }.find(*begin) != string::npos)
        return Unescape{ string(1, *begin), 2 };

    size_t nDigits;
    string str;

    for (nDigits = 0; nDigits != 3; ++nDigits)  // inspect octal digits
    {
        int ch = *(begin + nDigits);
        if (string{ "01234567" }.find(ch) == string::npos)
            break;                              // stop at 1st non octal
        str += ch;
    }

    if (nDigits != 0)                      // got octal digit escape seq.
        return Unescape{ string(
                            1, static_cast<char>(stoul(str, 0, 8)) 
                         ), nDigits + 1 };

    if (*begin == 'x')                 // maybe hex escape seq. ?
    {
        for (nDigits = 0; nDigits != 2; ++nDigits)  // inspect hex digits
        {
            int ch = *(begin + 1 + nDigits);
            if (not isxdigit(ch))
                break;                              // stop at 1st non hex
            str += ch;
        }

        return nDigits == 0 ?                      // no hex, only \x
                    Unescape{ "x", 2 }
                :
                    Unescape{ string( 
                                1, static_cast<char>(stoul(str, 0, 16)) 
                              ), nDigits + 2 };
    }

    return Unescape{ string(1, *begin), 2 };
}
