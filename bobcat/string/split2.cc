#include "string.ih"

/*
    Each character of the String is inspected in turn. The following
situations are recognized:

    The character is in the set of separators:
       If currently constructing an element, the element is finished, and the
        first non-separator is searched. The thus recognized separator is
        handled next.
    The character is a double quote:
       If not currently constructing an element, read all subsequent
        characters until a matching dquote is found. If, while doing so, an
        escape character is encountered, then add the escape char and the char
        following the escape char. Handle the recognized dquoted string next.
       If currently constructing an element, add the dquote to the current
        element. 
       If the end-of-string is encountered, flag an error.
    The character is a single quote:
       If not currently constructing an element, read all subsequent
        characters until a matching squote is found. If, while doing so, an
        escape character is encountered, then add the escape char and the char
        following the escape char. Handle the recognized squoted string next.
       If currently constructing an element, add the squote to the current
        element. 
       If the end-of-string is encountered, flag an error.
    The character is another character:
       If not currently constructing an element, read all subsequent
        characters until a separator or the end of the string is found. If,
        while doing so, escape character is encountered, then add the escape
        char and the char following the escape char. Handle the recognized
        squoted string next.
       
*/

size_t String::split(vector<SplitPair> *words, char const *sep,
                       bool addEmpty) const
{
    words->clear();

    const_iterator from = begin();
    const_iterator beyond = end();
    string separators(sep);
    
    const_iterator until;

    while (from != beyond)
    {
        Type type = nextField(&until, from,     // get the from field, `until'
                              separators);      // points beyond the field's
                                                // last character

                                    // see if it is a quoted string
        bool quoted = (type == DQUOTE || type == SQUOTE);

        from += quoted;             // skip the quote of quoted strings

                                    // add the field to `words'
        if (type != SEPARATOR || addEmpty)
            words->push_back(SplitPair(string(from, until), type));

                                    // update from: skip the quote of quoted
        from = until + quoted;      // strings 
    }

    return words->size();
}

