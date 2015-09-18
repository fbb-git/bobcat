#include "string.hh"

    // type should have been initialized to `NORMAL' by the caller

String::Type String::word(string const &str, ConstIter *until, 
                          ConstIter from, string const &separators)
{
    ConstIter beyond = str.end();

    while (true)
    {
        ++from;                     // accept the first (and next) character

        if 
        (
            from == beyond          // at the end or at a separator
            ||                      
            separators.find(*from) != string::npos
        )
        {
            *until = from;          // indicate the word's end
            return NORMAL;          // and a normal word
        }

        if (*from == '\\')          // handle the backslash: skip the next
        {                           // char 
            if (++from == beyond)   // oops, there's no next char. 
            {
                *until = from;      // return anyway
                return ESCAPED_END; // but indicate that it's an abnormal
            }                       // word
        }
    }
}


