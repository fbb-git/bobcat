#include "string.ih"

bool String::eosDq(FSAData &data)
{
    data.entry.second = DQUOTE_UNTERMINATED;
    data.entries->push_back(data.entry);
    return false;
}

