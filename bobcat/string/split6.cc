#include "string.hh"

String::SplitPair String::split(ConstIter &begin, ConstIter const &end,
                                    string const &separators)
{
    SplitPair ret(string(), NORMAL);

    bool empty = true;

    for (; begin != end; )
    {                                   // saw a separator
        if (separators.find(*begin) != string::npos)    
        {
                                        // non-empty strings: keep the sep. 
                                        // for the next call

            if (empty)                  // empty strings: return an empty
            {                           // string, and the SEPARATOR indicator
                ret.second = SEPARATOR; 
                ++begin;                // to the next char
            }

            break;                      // end the for-loop, finding 
        }                               // `return ret' at the end

        empty = false;

        switch (*begin)
        {
            case '"':           // dquoted string: accept all until the
            {                   // next, and then do unescape.
                SplitPair const &part = dquotedString(begin, end);

                ret.first += part.first;

                if (part.second == DQUOTE_UNTERMINATED)
                {
                    ret.second = DQUOTE_UNTERMINATED;
                    return ret;
                }
            }
            break;

            case '\'':          // quoted string: accept all until 
            {                   // the next ', without unescaping
                SplitPair const &part = quotedString(begin, end);

                ret.first += part.first;

                if (part.second == SQUOTE_UNTERMINATED)
                {
                    ret.second = SQUOTE_UNTERMINATED;
                    return ret;
                }
            }
            break;

            case '\\':          // unescape a lone escape sequence
            {
                IntType part(escapedString(begin, end));

                ret.first += part.first;
                if (part.second == ESCAPED_END)
                {
                    ret.second = ESCAPED_END;
                    return ret;
                }
            }
            break;

            default:            // add remaining chars to the next element
                ret.first += *begin++;
            break;
        }
    }
    return ret;
}










