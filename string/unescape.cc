#include "string.ih"

namespace
{
    char const escapeChars[] = "abfnrtv";
    char const escapeValue[] = {'\a', '\b', '\f', '\n', '\r', '\t', '\v'};

    unsigned handleOctal(String *dest, String const &src, unsigned pos)
    {
        size_t const nOct = 3;                // need exactly 3 octals

        unsigned pos2 = min(pos + nOct, 
                            src.find_first_not_of("01234567", pos));

        if (pos2 != pos + nOct)                 // need exactly nOct octals
        {
            *dest += src[pos];                  // add next char if not so
            return pos + 1;                     // next to handle
        }

        A2x a2x(src.substr(pos, nOct));

        unsigned ch;
        a2x >> oct >> ch;                       // convert substr. to octal
        *dest += static_cast<char>(ch);         // append the octal value
        return pos2;                            // pos. of next to handle
    }

    unsigned handleHex(String *dest, String const &src, unsigned pos)
    {
        size_t const nHex = 2;                // need exactly 2 hex digits

        ++pos;                                  // skip the 'x'
        unsigned pos2 = min(pos + nHex, 
                            src.find_first_not_of("01234567ABCDEF", pos));

        if (pos2 != pos + nHex)
        {
            *dest += src[pos - 1];              // add next char if not so
            return pos;                         // next to handle
        }

        A2x a2x(src.substr(pos, nHex));
        unsigned ch;
        a2x >> hex >> ch;                       // convert substr. to hex
        *dest += static_cast<char>(ch);         // append the hex value
        return pos2;                            // pos. of next to handle
    }
}

String String::unescape() const
{
    String ret;

    unsigned prefix = 0;                    // prefix text before \-char
    unsigned pos = 0;

    while (true)
    {
        pos = find('\\', pos);
        ret += substr(prefix, pos - prefix);// append prefix

        if (pos == string::npos)            // done if no more \-chars
            return ret;

        ++pos;                              // skip \-char

        if (pos == length())                // \-char terminates: remove it
            return ret;                     // since we're removing \-chars


        int next = (*this)[pos];            // determine next char

        if (char *cp = strchr(escapeChars, next))// escape sequence ?
        {
            ret += escapeValue[cp - escapeChars];// then assign escape char
            ++pos;                          // next character to handle
        }
        else if (strchr("01234567", next))  // handle octal values
            pos = handleOctal(&ret, *this, pos);

        else if (strchr("xX", next))        // handle hex values
            pos = handleHex(&ret, *this, pos);

        else                                // handle lone characters
            ret += (*this)[pos++];     

        prefix = pos; 
    }
}


