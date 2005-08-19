#include "string.ih"

String::const_iterator String::quoted(const_iterator from, int quote) const
{
    const_iterator beyond = end();

    while (true)
    {
        ++from;                     // skip the quote or next character

        if (from == beyond)         // missed the matching closing quote:
            return from;            // return, let the caller handle this
                                    // problem 

        if (*from == quote)         // matched quote found: done
            return from;

        if (*from == '\\')          // handle the backslash: skip the next
        {                           // char 
            if (++from == beyond)   // oops, there's no next char: let the
                return from;        // caller handle the non-terminated
        }                           // string.
    }
}


