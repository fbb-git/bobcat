#include "process.ih"

vector<string> Process::split(ConstIter begin, ConstIter const &end)
{
    vector<string> ret;
    string next;

    for (; begin != end; )
    {
        switch (*begin)
        {
            case '"':           // dquoted string: accept all until the
                                // next, and then do unescape.
                next += dquotedString(begin, end);
            break;

            case '\'':          // quoted string: accept all until 
                                // the next ', without unescaping
                next += quotedString(begin, end);
            break;

            case '\\':          // unescape a lone escape sequence
                next += escapedString(begin, end);
            break;

            case ' ':           // mere blanks end the current element.
            case '\t':
                if (next.length())
                {
                    ret.push_back(next);
                    next.clear();
                }
                ++begin;
            break;

            default:            // add remaining chars to the next element
                next += *begin++;
            break;
        }
    }

    if (next.length())          // add any remaining element
        ret.push_back(next);

    return ret;
}
