#include "process.ih"

// On entry, `begin' points at the beginning of the stand-alone escape
// character. 
// On exit, the character is unescaped and returned, and `begin' points
// immediately beyond the characters defining the escape-sequence.


int Process::escapedString(ConstIter &begin, ConstIter const &end)
{
    if (begin + 1 == end)           // at least one char. should follow
        throw Exception() << "Process " << d_command << ": trailing \\";

    string escaped(begin, end);     // local copy of the escaped text

                                    // cut the copy at the next backslash
    escaped = escaped.substr(0, escaped.find('\\', 1));
    size_t preLength = escaped.length();

                                    // unescape the escape-sequence
    escaped = String::unescape(escaped);

                                    // reposition begin beyond the chars of 
                                    // the escape sequence
    begin += 1 + preLength - escaped.length();

    return escaped[0];              // return the escaped character
}



