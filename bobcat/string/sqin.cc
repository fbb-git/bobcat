#include "string.ih"

bool String::sqIn(FSAData &data)
{
    ++data.begin;
    data.entry.second = SQUOTE;
    data.state = SQSTRING;
    return true;
}
