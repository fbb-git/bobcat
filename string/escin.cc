#include "string.ih"

bool String::escIn(FSAData &data)
{
    Unescape ue = unescape(data.begin, data.end);

    if (ue.length == 0)                 // illegal escape seq.
    {
        data.entry.first += '\\';
        data.entry.second = ESCAPED_END;
        data.entries->push_back(data.entry);
        return false;
    }

    data.begin += ue.length;            // skip beyond the esc. seq.
    data.entry.first += ue.str.front();   // add the converted esc. seq.

    return true;
}
