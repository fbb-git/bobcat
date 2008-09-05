#include "string.ih"

    // type should have been initialized to `NORMAL' by the caller

String::Type String::word(string const &str, const_iterator *until, 
                          const_iterator from, string const &separators)
{
    const_iterator beyond = str.end();

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


