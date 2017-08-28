#include "string.ih"

bool String::eosSq(FSAData &data)
{
    data.entry.second = SQUOTE_UNTERMINATED;
    data.entries->push_back(data.entry);
    return false;
}
