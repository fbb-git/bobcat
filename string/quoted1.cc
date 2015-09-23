#include "string.hh"

String::ConstIter String::quoted(string const &str,
                                    ConstIter from, int quote)
{
    ConstIter beyond = str.end();

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


