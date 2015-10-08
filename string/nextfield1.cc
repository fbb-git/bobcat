#include "string.ih"

String::Type String::nextField(string const &str, 
                    ConstIter *until, ConstIter from,
                    string const &separators)
{
    if (separators.find(*from) != string::npos) // saw a separator
    {                                           // get it, `*until' points 
        *until = separator(str, from, separators);   
                                                // beyond it.
        return SEPARATOR;
    }

    switch (*from)                              // handle all other cases
    {
        case '"':                               // d-quoted string
            *until = quoted(str, from, '"');
                                                // if pointing at the matching
                                                // " then it's ok, otherwise
                                                // an error was encountered
        return *until != str.end() ? DQUOTE : DQUOTE_UNTERMINATED;

        case '\'':    
            *until = quoted(str, from, '\'');
                                                // if pointing at the matching
                                                // ' then it's ok, otherwise
                                                // an error was encountered

        return *until != str.end() ? SQUOTE : SQUOTE_UNTERMINATED;

        default:                                // otherwise get the next word
        return word(str, until, from, separators);
    }
}

