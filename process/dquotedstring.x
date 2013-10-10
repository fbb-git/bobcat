#include "process.ih"

// On entry, `begin' points at the beginning of the double quoted string,
// on exit, the unescaped double quoted string (without the surrounding double
// quotes) is returned, and 'begin' points to the location immediately
// following the last double quote.

string Process::dquotedString(ConstIter &begin, ConstIter const &end)
{
    string dquoted;

    while (true)
    {
        if (++begin == end)
            throw Exception() << "Process " << d_command << ": unmatched \"";

        switch (*begin)
        {
            default:            // regular characters are added to dquoted
                dquoted += *begin;
            break;

            case '\\':      // backslash: accept it and accept the next char
                dquoted += '\\';

                if (begin + 1 == end)   // the \ was the last character
                    break;              // causing an error at the loop's top
                
                dquoted += *++begin;    // add the char beyond the \-char
            break;

            case '"':           // closing double quote observed
                ++begin;        // skip it
                                // return the unescaped double quoted string's
            return dquoted = String::unescape(dquoted); //            contents
        }
    }
}
