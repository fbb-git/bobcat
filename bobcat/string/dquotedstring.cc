#include "string.ih"

// On entry, `begin' points at the beginning of the double quoted string,
// on exit, the unescaped double quoted string (without the surrounding double
// quotes) is returned, and 'begin' points to the location immediately
// following the last double quote.

String::SplitPair String::dquotedString(ConstIter &begin, 
                                        ConstIter const &end)
{
    SplitPair ret(string(), DQUOTE);

    while (true)
    {
        if (++begin == end)
        {
            ret.second = DQUOTE_UNTERMINATED;
            return ret;
        }

        switch (*begin)
        {
            default:            // regular characters are added to ret
                ret.first += *begin;
            break;

            case '\\':      // backslash: accept it and accept the next char
                ret.first += '\\';

                if (begin + 1 == end)   // the \ was the last character
                    break;              // causing an error at the loop's top
                
                ret.first += *++begin;  // add the char beyond the \-char
            break;

            case '"':           // closing double quote observed
                ++begin;        // skip it
                                // return the unescaped double quoted string's
                                // contents
            ret.first = String::unescape(ret.first); 
            return ret;
        }
    }
}
