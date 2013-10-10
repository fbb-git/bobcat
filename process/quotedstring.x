#include "process.ih"

// On entry, `begin' points at the beginning of the quoted string, on exit,
// the quoted string (without the surrounding quotes) is returned, and 'begin'
// points to the location immediately following the last quote.
// 
// A single quoted string does not do \-escapes.

string Process::quotedString(ConstIter &begin, ConstIter const &end)
{
    string quoted;

    while (true)
    {
        if (++begin == end)
            throw Exception() << "Process " << d_command << ": unmatched '"; 

        if (*begin == '\'')             // stop at the next single quote
        {
            ++begin;                    // skip it
            return quoted;              // and return the string's contents
        }

        quoted += *begin;               // otherwise add the next char
    }
}


