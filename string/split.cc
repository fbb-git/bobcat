#include "string.ih"

size_t String::split(std::vector<std::string> *words, 
                char const *sep, bool addEmpty) const
{
    words->clear();

    const_iterator from = begin();
    const_iterator beyond = end();
    string separators(sep);
    
    const_iterator until;

    while (from != beyond)
    {
//cerr << "SCAN `" << string(from, beyond) << "'" << endl;

        Type type = nextField(&until, from,     // get the from field, `until'
                              separators);      // points beyond the field's
                                                // last character
//cerr << "\tFIELD: `" << string(from, until) << "'" << endl;
//cerr << "\tBEYOND: `" << string(until, beyond) << "'" << endl;

                                    // see if it is a quoted string
        bool quoted = (type == DQUOTE || type == SQUOTE);

        from += quoted;             // skip the quote of quoted strings

                                    // add the field to `words'
        if (type != SEPARATOR || addEmpty)
            words->push_back(string(from, until));

                                    // update from: skip the quote of quoted
        from = until + quoted;      // strings 
    }

    return words->size();
}

