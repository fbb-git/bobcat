#include "string.hh"

namespace
{
    char const escapeChars[] = "abfnrtv";
    char const escapeValue[] = {'\a', '\b', '\f', '\n', '\r', '\t', '\v'};

    size_t handleOctal(string *dest, string const &src, size_t pos)
    {
        size_t pos2 = min(src.length(), 
                          src.find_first_not_of("01234567", pos));

        if (pos2 == pos + 1 && src[pos] == '0') // saw \0
        {
            *dest += static_cast<char>(0);
            return pos2;
        }

        size_t const nOct = 3;                // need exactly 3 octals

        pos2 = min(pos + nOct, pos2);

        if (pos2 != pos + nOct)                 // need exactly nOct octals
        {
            *dest += src[pos];                  // add next char if not so
            return pos + 1;                     // next to handle
        }

        A2x a2x(src.substr(pos, nOct));

        size_t ch;
        a2x >> oct >> ch;                       // convert substr. to octal
        *dest += static_cast<char>(ch);         // append the octal value
        return pos2;                            // pos. of next to handle
    }

    size_t handleHex(string *dest, string const &src, size_t pos)
    {
        size_t const nHex = 2;                // need exactly 2 hex digits

        ++pos;                                  // skip the 'x'
        size_t pos2 = min(pos + nHex, 
                            src.find_first_not_of(
                                "0123456789abcdefABCDEF", pos));

        if (pos2 != pos + nHex)                 // found a hex character?
        {
            *dest += src[pos - 1];              // add next char if so
            return pos;                         // next char to handle
        }

        A2x a2x(src.substr(pos, nHex));
        size_t ch;
        a2x >> hex >> ch;                       // convert substr. to hex
        *dest += static_cast<char>(ch);         // append the hex value

        return pos2;                            // pos. of next to handle
    }
}

string String::unescape(string const &str)
{
    string ret;

    size_t prefix = 0;                    // prefix text before \-char
    size_t pos = 0;

    while (true)
    {
        pos = str.find('\\', pos);
        ret += str.substr(prefix, pos - prefix);// append prefix

        if (pos == string::npos)            // done if no more \-chars
            return ret;

        ++pos;                              // skip \-char

        if (pos == str.length())            // \-char terminates: remove it
            return ret;                     // since we're removing \-chars


        int next = str[pos];                // determine next char

        if (char const *cp = strchr(escapeChars, next))// escape sequence ?
        {
            ret += escapeValue[cp - escapeChars];// then assign escape char
            ++pos;                          // next character to handle
        }
        else if (strchr("01234567", next))  // handle octal values
            pos = handleOctal(&ret, str, pos);

        else if (next == 'x')               // handle hex values
            pos = handleHex(&ret, str, pos);
        else                                // handle lone characters
            ret += str[pos++];     

        prefix = pos; 
    }
}
