#include "string.ih"

// On entry, `begin' points at the beginning of the quoted string, on exit,
// the quoted string (without the surrounding quotes) is returned, and 'begin'
// points to the location immediately following the last quote.
// 
// A single quoted string does not do \-escapes.

String::SplitPair String::quotedString(ConstIter &begin, ConstIter const &end)
{
    SplitPair ret(string(), SQUOTE);

    while (true)
    {
        if (++begin == end)
        {
            ret.second = SQUOTE_UNTERMINATED;
            return ret;
        }

        if (*begin == '\'')             // stop at the next single quote
        {
            ++begin;                    // skip it
            return ret;              // and return the string's contents
        }

        ret.first += *begin;         // otherwise add the next char
    }
}






