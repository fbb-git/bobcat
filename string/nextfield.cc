#include "string.ih"

String::Type String::nextField(const_iterator *until, const_iterator from,
                                string const &separators) const
{
    if (separators.find(*from) != string::npos) // saw a separator
    {
        *until = separator(from, separators);   // get it, `*until' points 
                                                // beyond it.
        return SEPARATOR;
    }

    switch (*from)                              // handle all other cases
    {
        case '"':                               // d-quoted string
            *until = quoted(from, '"');
                                                // if pointing at the matching
                                                // " then it's ok, otherwise
                                                // an error was encountered
        return *until != end() ? DQUOTE : DQUOTE_UNTERMINATED;

        case '\'':    
            *until = quoted(from, '\'');
                                                // if pointing at the matching
                                                // ' then it's ok, otherwise
                                                // an error was encountered

        return *until != end() ? SQUOTE : SQUOTE_UNTERMINATED;

        default:
        return word(until, from, separators);   // otherwise get the next word
    }
}

